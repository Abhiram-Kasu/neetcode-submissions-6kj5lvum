class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        var map = new HashMap<HashMap<Character, Integer>, List<String>>();
        for(var str : strs){
            var key = processString(str);
            map.putIfAbsent(key, new ArrayList<>());
            map.get(key).add(str);
        }

        return new ArrayList<>(map.values());


        

    }

    public HashMap<Character, Integer> processString(String input){
        var map = new HashMap<Character, Integer>();

        for(var character : input.toCharArray()){
            map.put(character, map.getOrDefault(character, 0) + 1);
        }
        return map;
    }
}
