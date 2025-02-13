import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Main {
    static class Task {
        public final static String INPUT_FILE = "in";
        public final static String OUTPUT_FILE = "out";

        int n, m;
        int[] dist;

        private void readInput() {
            try {
                Scanner sc = new Scanner(new File(INPUT_FILE));
                n = sc.nextInt();
                m = sc.nextInt();
                dist = new int[n];
                for (int i = 0; i < n; i++) {
                    dist[i] = sc.nextInt();
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
            // TODO: Aflati numarul minim de opriri necesare pentru
            List<Integer> distante  = Arrays.stream( dist ).boxed().collect( Collectors.toList() );
            int nrOpriri = 0;
            int constanta = m;
            int benzina = constanta;
            boolean inceput = true;
            for (int i = 0; i < n-1; i++){
                if (inceput && m >= distante.get(n-1)){
                    nrOpriri = 0;
                    inceput = false;
                    break;
                }
                if (distante.get(i) == (distante.get(n-1) / 2)){
                    nrOpriri = 1;
                    break;
                }
                if (m <= distante.get(n-1)){
                    benzina -= distante.get(i);
                    if (benzina <= m && m <= distante.get(i+1)){
                        nrOpriri++;
                        m+= constanta;
                        benzina = constanta;
                    }
                    inceput = false;
                }
            }
            return nrOpriri;
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
