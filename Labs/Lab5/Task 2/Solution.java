import java.io.*;
import java.util.*;

public class Solution {
    static int n;

    private static void BKT(ArrayList<ArrayList<Integer>> all, ArrayList<Integer> sol, int poz){
        all.add(new ArrayList(sol));
        if (poz == n){
            return;
        }
        if (poz > 0){
            for (int i = sol.get(poz - 1) + 1; i <= n; i++){
                sol.add(i);
                BKT(all,sol,poz+1);
                sol.remove(sol.size()-1);
            }
        } else {
            for (int i = 1; i <= n; i++){
                sol.add(i);
                BKT(all,sol,poz+1);
                sol.remove(sol.size()-1);
            }
        }
    }


    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        sc.close();
        ArrayList<ArrayList<Integer>> all = new ArrayList<>();
        ArrayList<Integer> sol = new ArrayList<>();
        BKT(all,sol,0);
        System.out.println(all.size());
        for (ArrayList<Integer> arr : all) {
            for (int i = 0; i < arr.size(); i++) {
                if (i + 1 == arr.size()) {
                    System.out.println(arr.get(i));
                } else {
                    System.out.print(arr.get(i) + " ");
                }
            }
        }
    }
}