import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.lang.reflect.Array;
import java.util.*;
import java.util.function.Function;
import java.util.function.ToDoubleFunction;
import java.util.function.ToIntFunction;
import java.util.function.ToLongFunction;

public class Main {
    static class Obj {
        public int weight;
        public int price;

        public Obj() {
            weight = 0;
            price = 0;
        }
    }

    static class Sort implements Comparator<Obj> {
        public int compare(Obj a, Obj b) {
            if (b.price / (double) b.weight < a.price / (double) a.weight) {
                return -1;
            } else if (b.price / (double) b.weight > a.price / (double) a.weight){
                return 1;
            } else {
                return 0;
            }
        }

        @Override
        public Comparator<Obj> reversed() {
            return null;
        }

        @Override
        public Comparator<Obj> thenComparing(Comparator<? super Obj> other) {
            return null;
        }

        @Override
        public <U> Comparator<Obj> thenComparing(Function<? super Obj, ? extends U> keyExtractor, Comparator<? super U> keyComparator) {
            return null;
        }

        @Override
        public <U extends Comparable<? super U>> Comparator<Obj> thenComparing(Function<? super Obj, ? extends U> keyExtractor) {
            return null;
        }

        @Override
        public Comparator<Obj> thenComparingInt(ToIntFunction<? super Obj> keyExtractor) {
            return null;
        }

        @Override
        public Comparator<Obj> thenComparingLong(ToLongFunction<? super Obj> keyExtractor) {
            return null;
        }

        @Override
        public Comparator<Obj> thenComparingDouble(ToDoubleFunction<? super Obj> keyExtractor) {
            return null;
        }
    }

    static class Task {
        public final static String INPUT_FILE = "in";
        public final static String OUTPUT_FILE = "out";

        int n, w;
        Obj[] objs;

        private void readInput() {
            try {
                Scanner sc = new Scanner(new File(INPUT_FILE));
                n = sc.nextInt();
                w = sc.nextInt();
                objs = new Obj[n];
                for (int i = 0; i < n; i++) {
                    objs[i] = new Obj();
                    objs[i].weight = sc.nextInt();
                    objs[i].price = sc.nextInt();
                }
                sc.close();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }

        private void writeOutput(double result) {
            try {
                PrintWriter pw = new PrintWriter(new File(OUTPUT_FILE));
                pw.printf("%.4f\n", result);
                pw.close();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }

        private double getResult() {
            List<Obj> objects = Arrays.asList(objs);
            double result = 0d,fraction,raport,x,W = w;
            boolean modified = false;
            Collections.sort(objects, new Sort());
            for (int i = 0; i < n; i++) {
                if (W != 0) {
                    if (!modified && objects.get(i).weight > W) {
                        modified = true;
                        raport = objects.get(i).price / (double) objects.get(i).weight;
                        result = W * raport;
                        W = 0;
                        continue;
                    }
                    if (objects.get(i).weight <= W) {
                        modified = true;
                        result += objects.get(i).price;
                        W -= objects.get(i).weight;
                        continue;
                    }
                    if (modified && objects.get(i).weight > W) {
                        raport = objects.get(i).price / (double) objects.get(i).weight;
                        x = W *raport;
                        fraction = x / raport;
                        W -= fraction;
                        result += x;
                    }
                }
            }
            return result;
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
