import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;
import java.util.function.Function;
import java.util.function.ToDoubleFunction;
import java.util.function.ToIntFunction;
import java.util.function.ToLongFunction;

public class Main {
    static class Homework {
        public int deadline;
        public int score;

        public Homework() {
            deadline = 0;
            score = 0;
        }
    }

    static class Sort implements Comparator<Homework> {
        public int compare(Homework a, Homework b){
            if (a.score < b.score){
                return 1;
            } else if (a.score >= b.score){
                return -1;
            } else {
                return 0;
            }
        }

        @Override
        public Comparator<Homework> reversed() {
            return null;
        }

        @Override
        public Comparator<Homework> thenComparing(Comparator<? super Homework> other) {
            return null;
        }

        @Override
        public <U> Comparator<Homework> thenComparing(Function<? super Homework, ? extends U> keyExtractor, Comparator<? super U> keyComparator) {
            return null;
        }

        @Override
        public <U extends Comparable<? super U>> Comparator<Homework> thenComparing(Function<? super Homework, ? extends U> keyExtractor) {
            return null;
        }

        @Override
        public Comparator<Homework> thenComparingInt(ToIntFunction<? super Homework> keyExtractor) {
            return null;
        }

        @Override
        public Comparator<Homework> thenComparingLong(ToLongFunction<? super Homework> keyExtractor) {
            return null;
        }

        @Override
        public Comparator<Homework> thenComparingDouble(ToDoubleFunction<? super Homework> keyExtractor) {
            return null;
        }
    }

    static class Task {
        public final static String INPUT_FILE = "in";
        public final static String OUTPUT_FILE = "out";

        int n;
        Homework[] hws;

        private void readInput() {
            try {
                Scanner sc = new Scanner(new File(INPUT_FILE));
                n = sc.nextInt();
                hws = new Homework[n];
                for (int i = 0; i < n; i++) {
                    hws[i] = new Homework();
                    hws[i].deadline = sc.nextInt();
                    hws[i].score = sc.nextInt();
                }
                sc.close();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }

        private void writeOutput(int result) {
            try {
                PrintWriter pw = new PrintWriter(new File(OUTPUT_FILE));
                pw.printf("%d\n", result);
                pw.close();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }

        private int getResult() {
            // TODO: Aflati punctajul maxim pe care il puteti obtine
            int saptamana = 0;
            int punctaj = 0;
            List<Homework> homeworks = Arrays.asList(hws);
            Collections.sort(homeworks, new Sort());
            for (int i = 0; i < n ; i++){
                if (homeworks.get(i).deadline >= saptamana){
                    punctaj += homeworks.get(i).score;
                    saptamana++;
                }
            }
            return punctaj;
        }

        public void solve() {
            readInput();
            writeOutput(getResult());
        }
    }

    public static void main(String[] args) {
        new Task().solve();
    }
}
