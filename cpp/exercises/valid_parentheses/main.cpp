#include <iostream>
#include <string>
#include <vector>

bool isValid(std::string s) {
    std::vector<char> stack;
    for (char c : s) {
        switch (c) {
            case '(':
                stack.push_back(')');
                break;
            case '{':
                stack.push_back('}');
                break;
            case '[':
                stack.push_back(']');
                break;
            case ')':
            case '}':
            case ']': {
                if (stack.empty()) return false;
                char last = stack.back();
                stack.pop_back();
                if (c != last) return false;
                break;
            }
        }
    }
    return stack.empty();
}

int main() {
    std::cout << isValid("()") << std::endl;
    std::cout << isValid("()[]{}") << std::endl;
    std::cout << isValid("(]") << std::endl;
}