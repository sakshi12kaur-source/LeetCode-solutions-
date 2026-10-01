class Solution {

    public boolean isValid(String s) {

        char[] inputChar = s.toCharArray();

        Map<Character, Character> braceMap = new HashMap<>();
        braceMap.put('(', ')');
        braceMap.put('{', '}');
        braceMap.put('[', ']');

        Stack<Character> stack = new Stack<>();

        for (Character brace : inputChar) {

            if (braceMap.containsKey(brace)) {
                stack.push(brace);
            } else {

                if (stack.empty() || brace != braceMap.get(stack.pop())) {
                    return false;
                }
            }
        }

        return stack.empty();
    }
}