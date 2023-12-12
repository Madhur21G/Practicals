#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define StackSize 100

struct stack{
    int top;
    int items[StackSize];
};

int empty(struct stack *st){
    if(st->top == -1) return 1;
    else return 0;
}

void push(struct stack *st, int x){
    st->items[++(st->top)] = x;
}

int pop(struct stack *st){
    if(empty(st)){
        printf("Stack is empty");
        exit(1);
    }
    int x = st->items[st->top];
    (st->top)--;
    return x;
}

int stacktop(struct stack *st){
    if(empty(st)){
        printf("Stack is empty");
        exit(1);
    }
    else{
        int x = st->items[st->top];
        return x;
    }
}

int operand(char ch){
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '$') return 1;
    return 0;
}

int precedence(char op1, char op2){
    if (op1 == '$'){
        return 1;
    }
    else if (op2 == '$'){
        return 0;
    }

    if (op1 == '*'){
        return 1;
    }
    else if (op2 == '*'){
        return 0;
    }

    if (op1 == '/'){
        return 1;
    }
    else if (op2 == '/'){
        return 0;
    }

    if (op1 == '+'){
        return 1;
    }
    else if (op2 == '+'){
        return 0;
    }

    if (op1 == '-'){
        return 1;
    }
    else if (op2 == '-'){
        return 0;
    }
}

int paranthesis_checking(char arr[]){
    struct stack st;
    int i = 0;
    st.top = -1;
    while(arr[i] != '/0'){
        if(arr[i] == '[' || arr[i] == '(' || arr[i] == '{'){
            push(&st, arr[i]);
        }
        else{
            if(st.top == 0) return 0;
            char el = pop(&st);
            if(arr[i] == '('){
                if(el != ')') return 0;
            }
            else if(arr[i] == '['){
                if(el != ']') return 0;
            }
            else if(arr[i] == '{'){
                if(el != '}') return 0;
            }
        }
        i++;
    }
    if(st.top != 0) return 0;
    return 1;
}

int exp_evaluation(char arr[]){
    struct stack st;
    st.top = -1;
    int i = 0;
    while(arr[i] != '/0'){
        int curr = arr[i];
        if(curr >= '0' && curr <= '9'){
            push(&st, curr);
        }
        else{
            int ele1 = pop(&st);
            int ele2 = pop(&st);
            int res;
            if (curr == '+'){
                res = ele1 + ele2;
            }
            else if (curr == '/'){
                res = ele2 / ele1;
            }
            else if (curr == '-'){
                res = ele2 - ele1;
            }
            else if (curr == '*'){
                res = ele1 * ele2;
            }
            else if (curr == '$'){
                res = pow(ele2, ele1);
            }
            push(&st, res);
        }
        i++;
    }
    return stacktop(&st);
}

char *infix_postfix(char exp[]){
    struct stack open_stk;
    open_stk.top = -1;
    char *postfix = (char *)malloc(100 * (sizeof(char)));
    int j = 0;
    int i = 0;
    while (exp[i] != '\0'){
        char symb = exp[i];
        if (!operand(symb)){
            postfix[j] = symb;
            j++;
        }
        else{
            while (!empty(&open_stk) && precedence(stacktop(&open_stk), symb)){
                char top_symb = pop(&open_stk);
                postfix[j] = top_symb;
                j++;
            }
            push(&open_stk, symb);
        }
        i++;
    }
    while (!empty(&open_stk)){
        char top_symb = pop(&open_stk);
        postfix[j++] = top_symb;
    }
    postfix[j] = '\0';
    return postfix;
}

char *infix_to_prefix(char input[]){
    struct stack op_stack;
    struct stack num_stack;
    struct stack temp_stack;
    op_stack.top = -1;
    num_stack.top = -1;
    temp_stack.top = -1;
    int i = 0;
    while (input[i] != 0){
        char symb = input[i];
        if (operand(symb)){
            push(&op_stack, symb);
        }
        else{
            push(&num_stack, symb);
        }
        i++;
    }
    char *reversed_string = (char *)malloc(50 * sizeof(char));
    int j = 0;

    // add the first number
    reversed_string[j++] = pop(&num_stack);

    while (!empty(&num_stack)){
        struct stack temp_op;
        temp_op.top = -1;

        while (!empty(&op_stack)){
            char op = pop(&op_stack);
            reversed_string[j++] = pop(&num_stack);
            push(&temp_op, op);
            if (empty(&op_stack)){
                reversed_string[j++] = op;
                break;
            }
            while (precedence(stackTop(&op_stack),op)){
                push(&temp_op, pop(&op_stack));
                reversed_string[j++] = pop(&num_stack);
                if (empty(&op_stack))break;
            }
            while (!empty(&temp_op)){
                reversed_string[j++] = pop(&temp_op);
            }
        }
    }
    reversed_string[j] = '\0';
    return strrev(reversed_string);
}

int main(){

}
