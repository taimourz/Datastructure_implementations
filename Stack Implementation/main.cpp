#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include<queue>
using namespace std;

class Stack {
    public: 
        int* arr;
        int top; 
        int size;

        Stack(int size) {
            this->size = size;
            arr = new int[size];
            top = -1;
        }


        void push(int data) {
            if (size - top > 1) {
                top++;
                arr[top] = data;
            }
            else {
                cout << "Stackoverflow in push" << endl;
            }
        }

        void pop() {
            if (top >= 0) {
                top--;
            }
            else {
                cout << "Stackoverflow in pop" << endl;
            }
        }

        int peek() {
            return arr[top];
        }

        bool isEmpty() {    
            if (top == -1) {
                return true;
            }
            else {
                return false;
            }
        }

};

int main()
{
    Stack stk(2);
    stk.push(2);
    stk.push(3);
    // stk.push(3); // this will cause stackoverflow b/c stack size is 2

    while (!stk.isEmpty()) {
        cout << stk.peek()<< " ";
        stk.pop();
    }    
    // stk.pop(); // this will fail b/c stack is empty now
}