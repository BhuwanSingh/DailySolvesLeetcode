class Solution {
    public boolean isValid(String s) {
        char[] br = s.toCharArray();
        Stack<Character> st = new Stack<Character>();
        for( char b : br ) {
            switch( b ) {
                case ')':
                    if ( !st.empty() && st.peek() == '(' ) {
                        st.pop();
                    } else {
                        return false;
                    }
                    break;
                case '}':
                    if ( !st.empty() && st.peek() == '{' ) {
                        st.pop();
                    } else {
                        return false;
                    }
                    break;
                case ']':
                    if ( !st.empty() && st.peek() == '[' ) {
                        st.pop();
                    } else {
                        return false;
                    }
                    break;
                default:
                    st.push(b);
            }
        }
        return st.empty() == true;
    }
}