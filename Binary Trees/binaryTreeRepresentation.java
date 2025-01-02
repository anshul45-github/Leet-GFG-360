import java.util.ArrayList;

class Solution {
    public static void helper(Node root, ArrayList<Integer> v, int i) {
        if(root == null)
            return;
        if((2 * i) + 1 < v.size())
            root.left = new Node(v.get((2 * i) + 1));
        if((2 * i) + 2 < v.size())
            root.right = new Node(v.get((2 * i) + 2));
        helper(root.left, v, (2 * i) + 1);
        helper(root.right, v, (2 * i) + 2);
    }
    public static void createTree(Node root0, ArrayList<Integer> v ){
        helper(root0, v, 0);
    }
}
