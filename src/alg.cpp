// Copyright 2021 NNTU-CS
#include <string>
#include "tstack.h
int prioritet (char value) {
    switch (value) {
      case '(': return 0;
          break;
      case ')': return 1;
          break;
      case '+': return 2;
          break;
      case '-': return 2;
          break;
      case '*': return 3;
          break;
      case '/': return 3;
          break;
      default: return -1;
    }
}

std::string infx2pstfx(std::string inf) {
 Tstack <char> Stack1;
    int prioritet;
char arr;
char begin = 0;
std::string total;
for (int i = 0; i < inf.length(); i++) {
 arr = inf[i];
    prioritet = sequence(arr);
    if (prioritet > -1) {
        if ((prioritet == 0 || prioritet > sequence(begin) || Stack1.isEmpty()) && arr != ')') {
                if (Stack1.isEmpty())
 begin = arr;
            Stack1.push(arr);
        } else if (arr == ')') {
                while (Stack1.get() != '(') {
 total.push_back(Stack1.get());
 total.push_back(' ');
                    Stack1.pop();
                }
            Stack1.pop();
                if (Stack1.isEmpty())
                    begin = 0;
            }
        else {
                while (!Stack1.isEmpty() && sequence(Stack1.get()) >= prioritet) {
 total.push_back(Stack1.get());
 total.push_back(' ');
                    Stack1.pop();
                }
            if (Stack1.isEmpty())
 begin = inf[i];
            Stack1.push(inf[i]);
        }
    }
        else {
            total.push_back(arr);
            total.push_back(' ');
        }
    }
    while (!Stack1.isEmpty()) {
 total.push_back(Stack1.get());
 total.push_back(' ');
        Stack1.pop();
    }
    total.erase(total.end() - 1, total.end());
  return total;
}

int eval(std::string pst) {
  TStack <int> Stack2;
  int amount;
  for (int i = 0; i < pst.length(); i++) {
    if (pst[i] >= '0' && pst[i] <= '9') {
        Stack2.push(pst[i] - '0');
    }
    else if (pst[i] != ' ') {
      int val2 = Stack2.get();
 Stack2.pop();
      int val1 = Stack2.get();
        Stack2.pop();
  switch(pst[i]) {
      case '*': Stack2.push(val1 * val2);
          break;
        case '/': Stack2.push(val1 / val2);
            break;
        case '+': Stack2.push(val1 + val2);
            break;
        case '-': Stack2.push(val1 - val2);
            break;
        default: return -1;
      }
    }
  }
  amount = Stack2.get();
  return amount;
}
