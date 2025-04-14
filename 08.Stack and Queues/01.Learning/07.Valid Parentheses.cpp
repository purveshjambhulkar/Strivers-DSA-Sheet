import java.util.Stack;

class Solution {
    public boolean isValid(String s) {
        Stack<Character> st = new Stack<>();

        for (char ch : s.toCharArray()) {

            // Push opening brackets
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } else {
                // If closing bracket but stack is empty, it's invalid
                if (st.isEmpty()) {
                    return false;
                }

                char top = st.peek();

                // Check for correct matching pairs
                if ((top == '(' && ch == ')') ||
                    (top == '{' && ch == '}') ||
                    (top == '[' && ch == ']')) {
                    st.pop(); // Valid match, pop the top
                } else {
                    return false; // Mismatched bracket
                }
            }
        }

        // Final check: stack should be empty if all brackets matched
        return st.isEmpty();
    }
}
