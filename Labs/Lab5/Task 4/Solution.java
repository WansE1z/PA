import java.util.ArrayList;
import java.util.Scanner;

public class Solution {
    static int n, k;
    static char[] chars;
    static int[] freq;

    private static void backtracking(ArrayList<ArrayList<Character>> dom, ArrayList<Character> sol, int len, int poz){
        int size = sol.size(),contor = 0,i,flag;
        if (poz == len){
            dom.add(new ArrayList<>(sol));
            return;
        }

        for (i = 1; i < chars.length; i++){
            if (freq[i] > 0){
                sol.add(chars[i]);
                freq[i]--;
                for (int j = size - 2; j>= 0 && sol.get(j) == sol.get(j + 1);j--){
                    if (++contor == k){
                        flag = 0;
                    }
                }
                flag = 1;
                if (flag == 1){
                    backtracking(dom,sol,len, poz+1);
                }
                sol.remove(sol.size() - 1);
                freq[i]++;
            }
        }
    }

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        ArrayList<ArrayList<Character>> domeniu = new ArrayList<>();
        ArrayList<Character> solutie = new ArrayList<>();
        int len = 0;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        k = sc.nextInt();
        String s = sc.next().trim();
        s = " " + s;
        chars = s.toCharArray();
        freq = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            freq[i] = sc.nextInt();
        }
        sc.close();
        for (int f : freq){
            len += f;
        }
        backtracking(domeniu, solutie, len,0);
        System.out.println(domeniu.size());
        for (ArrayList<Character> arr : domeniu){
            for (int i = 0; i < arr.size(); i++){
                System.out.print(arr.get(i));
            }
            System.out.println();
        }
    }



}