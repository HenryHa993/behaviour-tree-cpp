#pragma once
#include <coroutine>
#include <utility>

enum NodeState
{
	RUNNING,
	SUCCESS,
	FAILURE
};

// Wrapper type
struct NodeTask
{

	// Promise type
	struct promise_type
	{
		// This is the NodeState returned from a coroutine
		NodeState NodeResult;

		void unhandled_exception() {};
		NodeTask get_return_object() { return NodeTask(this); };

		std::suspend_always initial_suspend() noexcept { return{}; }

		// Upon co_yield, suspend action
		// This should only be run when a RUNNING state is returned
		std::suspend_always yield_value(NodeState State) noexcept
		{
			NodeResult = State;
			return{};
		}

		// co_return is run when a definite state (SUCCESS or FAILURE) is reached
		void return_value(NodeState FinalState) noexcept { NodeResult = FinalState; }

		// Suspend before coroutine end, to prevent lifetime errors
		std::suspend_always final_suspend() noexcept { return{}; }
	};

	using Handle = std::coroutine_handle<promise_type>;
	Handle mCoroHdl{};

	explicit NodeTask(promise_type* p) : mCoroHdl(Handle::from_promise(*p)) {}
	NodeTask(NodeTask&& rhs) :mCoroHdl{ std::exchange(rhs.mCoroHdl, nullptr) } {}

	~NodeTask()
	{
		if (mCoroHdl)
		{
			mCoroHdl.destroy();
		}
	}

	NodeState Run()
	{
		// Might check 
		if (mCoroHdl && !mCoroHdl.done())
		{
			mCoroHdl.resume();
		}

		return mCoroHdl.promise().NodeResult;

	}

	bool Finished() const { return mCoroHdl.done(); }

};

