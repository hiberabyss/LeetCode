describe("StackUsingQueues", function(){
	var Stack = require('../implement-stack-using-queues');
	var stack;

	beforeEach(function() {
		stack = new Stack();
	});

	it("empty stack", function(){
		expect(stack.empty()).toBeTruthy();
	});

	it("push and pop", function(){
		stack.push(1);
		stack.push(2);
		stack.push(3);
		expect(stack.empty()).toBeFalsy();
		expect(stack.top()).toEqual(3);
		expect(stack.pop()).toEqual(3);
		expect(stack.pop()).toEqual(2);
		expect(stack.pop()).toEqual(1);
		expect(stack.empty()).toBeTruthy();
	});
});
