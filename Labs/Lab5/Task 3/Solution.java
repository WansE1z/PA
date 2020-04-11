import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

class Main {
    private static boolean isSafe(int row, int col, ArrayList<Integer> solution) {
        for (int i = 1; i < row; i++) {
            if (solution.get(i) == col) {
                return false;
            }

            if (col - solution.get(i) == row - i) {
                return false;
            }

            if (solution.get(i) - col == row - i) {
                return false;
            }
        }
        return true;
    }

    private static boolean solveSol(int col, ArrayList<Integer> sol,int n) {
        if (col > n) {
            return true;
        }

        for (int i = 1; i <= n; i++) {
            if (!isSafe(col, i, sol)) {
                continue;
            }

            sol.set(col, i);

            if (solveSol(col + 1, sol,n)) {
                return true;
            }
            sol.set(col, 0);
        }
        return false;
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.close();
        ArrayList<Integer> sol = new ArrayList<Integer>();
        for (int i = 0; i <= n + 1; i++)
            sol.add(0);
        sol.set(n + 1, 0);
        solveSol(1, sol,n);
        for (int i = 1; i <= n; i++) {
            if (i == n){
                System.out.println(sol.get(i));
            } else {
                System.out.print(sol.get(i) + " ");
            }
        }
    }
}

