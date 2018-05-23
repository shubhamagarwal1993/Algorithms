class CallHandler {

	private:
		CallHandler instance;

		/* 3 levels of employees: respondents, managers, directors */
		int LEVELS = 3;

		/* Initialize 10 respondents, 4 managers, and 2 directors */
		int NUM_RESPONDENTS = 10;
		int NUM_MANAGERS = 4;
		int NUM_DIRECTORS = 2;

		/* List of employees, by level.
		 * employeeLevels[0] = respondents
		 * employeeLevels[1] = managers
		 * employeeLevels[2] = directors
		*/
		List<List<Employee>> employeeLevels;

		/* queues for each call's rank */
		List<List<Call>> callQueues;

	public:
		CallHandler() { ... }

		/* Get instance of singleton class. */
		CallHandler getlnstance() {
			if(instance == null)
				instance = new CallHandler();
			return instance;
		}

		/* Gets the first available employee who can handle this call. */
		Employee getHandlerForCall(Call call) { ... }

		/* Routes the call to an available employee, or saves in a queue * if no employee available. */
		void dispatchCall(Caller caller) {
			Call call = new Call(caller);
			dispatchCall(call);
		}

		/* Routes the call to an available employee, or saves in a queue * if no employee available. */
		void dispatchCall(Call call) {
			/* Try to route the call to an employee with minimal rank. */
			Employee emp = getHandlerForCall(call);
			if(emp != null) {
				emp.receiveCall(call);
				call . setHandler (emp) ; 
			} else {
				/* Place the call into corresponding call queue according * to its rank. */
				call.reply ("Please wait for free employee to reply");
				callQueues.get (call.getRank().getValue()).add(call); 
			}
		}

		/* An employee got free. Look for a waiting call that emp. can * serve. Return true if we assigned a call, false otherwise. */
		public boolean assignCall(Employee emp) { ... }
};

class Call {

	private:
		Rank rank;
		Caller caller;
		Employee handler;

	public:
		Call(Caller c) {
			rank = Rank.responder;
			caller = c;
		}

		// Set emplpyee who is handling call
		void setHandler(Employee e) {
			handler = e;
		}

		void reply(String message) {}
		Rank getRank() { return rank; }
		void setRank(Rank r) { rank = r; }
		Rank incrementRank() { ... }
		void disconnect() { ... }
}

class Employee {
	
	private:
		Call currentCall = null;
		Rank rank;

	public:
		Employee() { }

		/* Start the conversation */
		void receiveCall(Call call) { ... }

		/* the issue is resolved, finish the call */
		void callCompleted() { ... }

		/* The issue has not been resolved. Escalate the call, and assign a new call to the employee. */
		void escalateAndReassign() { ... }

		/* Assign a new call to an employee, if the employee is free. */
		bool assignNewCall() { ... }

		/* Returns whether or not the employee is free. */
		bool isFree() {
			return currentCall == null;
		}

		Rank getRank() {
			return rank;
		}
};

class Respondent extendes Employee {

	public:
		Respondent() {
			rank = Rank.Responder;
		}
};

class Manager extendes Employee {

	public:
		Manager() {
			rank = Rank.Manager;
		}
};

class Director extendes Employee {

	public:
		Director() {
			rank = Rank.Director;
		}
};