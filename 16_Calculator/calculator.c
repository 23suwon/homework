#include "calculator.h"
#include "ArrayStack.h"

int infixToPostfix(char* infix, char* postfix) {
	int j = 0;
	ArrayStack* opStack = createArrayStack(100, CHARACTER);

	printf("Transform:\n");

	for (int i = 0; infix[i] != '\0'; i++) {
		if (infix[i] >= '0' && infix[i] <= '9') {
			if (j > 0) postfix[j++] = ' ';
			postfix[j++] = infix[i];
			postfix[j] = '\0';

			printf("- Postfix: %s | Stack: ", postfix);
			printArrayStack(opStack);
			printf("\n");
		}

		else if (infix[i] == '+' || infix[i] == '-' ||
			infix[i] == '*' || infix[i] == '/') {

			while (!emptyArrayStack(opStack)) {
				stackElement prevOp = peekArrayStack(opStack);

				if (precedence(infix[i]) <= precedence(prevOp.operator)) {
					stackElement popped = popArrayStack(opStack);
					if (j > 0) postfix[j++] = ' ';
					postfix[j++] = popped.operator;
					postfix[j] = '\0';
				}
				else {
					break;
				}
			}
			stackElement el;
			el.operator=infix[i];
			pushArrayStack(opStack, el);

			printf("- Postfix: %s | Stack: ", postfix);
			printArrayStack(opStack);
			printf("\n");
		}
		else if (infix[i] == '(') {
			stackElement el;
			el.operator = infix[i];
			pushArrayStack(opStack, el);

			printf("- Postfix: %s | Stack: ", postfix);
			printArrayStack(opStack);
			printf("\n");
		}
		else if (infix[i] == ')') {
			do
			{
				stackElement prevOp = popArrayStack(opStack);

				if (prevOp.operator != '(') {
					if (j > 0) postfix[j++] = ' ';
					postfix[j++] = prevOp.operator;
					postfix[j] = '\0';
				}
				if (prevOp.operator == '(') {
					break;
				}
			} while (!emptyArrayStack(opStack));

			printf("- Postfix: %s | Stack: ", postfix);
			printArrayStack(opStack);
			printf("\n");
		}
	}

	while (!emptyArrayStack(opStack)) {
		stackElement popped = popArrayStack(opStack);
		if (j > 0) postfix[j++] = ' ';
		postfix[j++] = popped.operator;
		postfix[j] = '\0';
	}
	printf("- Postfix: %s | Stack: ", postfix);
	printArrayStack(opStack);
	printf("\n");

	printf("\n- Result: %s\n", postfix);
}

int evalPostfix(char* postfix) {
	ArrayStack* valueStack = createArrayStack(100, INTEGER);
	int i = 0;

	printf("\nEval:\n");
	printf("- Postfix: %s\n", postfix);

	while (postfix[i] != '\0') {
		if (postfix[i] == ' ') { i++; continue; }
		if (postfix[i] >= '0' && postfix[i] <= '9') {
			stackElement el;
			el.value = (int)(postfix[i] - '0');
			pushArrayStack(valueStack, el);

			printf("- Current: %c | Stack: ", postfix[i]);
			printArrayStack(valueStack);
			printf("\n");
		}
		else if (postfix[i] == '*') {
			stackElement i1 = popArrayStack(valueStack);
			stackElement i2 = popArrayStack(valueStack);
			stackElement res;
			res.value = i2.value * i1.value;

			pushArrayStack(valueStack, res);

			printf("- Current: %c | Stack: ", postfix[i]);
			printArrayStack(valueStack);
			printf("\n");
		}
		else if (postfix[i] == '/') {
			stackElement i1 = popArrayStack(valueStack);
			stackElement i2 = popArrayStack(valueStack);
			stackElement res;
			res.value = i2.value / i1.value;
			pushArrayStack(valueStack, res);

			printf("- Current: %c | Stack: ", postfix[i]);
			printArrayStack(valueStack);
			printf("\n");
		}
		else if (postfix[i] == '+') {
			stackElement i1 = popArrayStack(valueStack);
			stackElement i2 = popArrayStack(valueStack);
			stackElement res;
			res.value = i2.value + i1.value;
			pushArrayStack(valueStack, res);

			printf("- Current: %c | Stack: ", postfix[i]);
			printArrayStack(valueStack);
			printf("\n");
		}
		else if (postfix[i] == '-') {
			stackElement i1 = popArrayStack(valueStack);
			stackElement i2 = popArrayStack(valueStack);
			stackElement res;
			res.value = i2.value - i1.value;
			pushArrayStack(valueStack, res);

			printf("- Current: %c | Stack: ", postfix[i]);
			printArrayStack(valueStack);
			printf("\n");
		}

		i++;
	}

	stackElement result = popArrayStack(valueStack);
	printf("\n- Result: %d\n", result.value);
	return result.value;
}

int precedence(char op) {
	switch (op)
	{
	case ')':
		return 3;
	case '*':
	case '/':
		return 2;
	case '+':
	case '-':
		return 1;
	case '(':
		return 0;
	default:
		return 0;
	}
}