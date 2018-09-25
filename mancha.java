import java.io.BufferedReader;
import java.io.InputStreamReader;

public class mancha {
    public static void main (String[] args)
    {
        try
        {
            BufferedReader leitor = new BufferedReader(new InputStreamReader(System.in));
            int N;

            N = Integer.parseInt(leitor.readLine());

            String[][] imagem = new String[N][N];
            String[] linha;
            for (int i=0; i < N; i++)
            {
                linha = leitor.readLine().split("");
                for (int j = 0; j < N; j++)
                    imagem[i][j] = linha[j];
            }
            
            boolean naoPodeHaverMais;
            String anterior;
            for (int i=0; i<N; i++)
            {
                naoPodeHaverMais = false;
                anterior = ".";
                for (int j=0; j<N; j++)
                {
                    if (anterior.equals(".") && imagem[i][j].equals("*") && naoPodeHaverMais)
                    {
                        System.out.println("N");
                        return;
                    }
                    if (anterior.equals("*") && imagem[i][j].equals("."))
                        naoPodeHaverMais = true;
                    
                    if (imagem[i][j].equals("."))
                    {
                        anterior = ".";
                    } else
                    if (imagem[i][j].equals("*"))
                    {
                        anterior = "*";
                    }
                }
            }
            
            for (int j=0; j<N; j++)
            {
                naoPodeHaverMais = false;
                anterior = ".";
                for (int i=0; i<N; i++)
                {
                    if (anterior.equals(".") && imagem[i][j].equals("*") && naoPodeHaverMais)
                    {
                        System.out.println("N");
                        return;
                    }
                    if (anterior.equals("*") && imagem[i][j].equals("."))
                        naoPodeHaverMais = true;
                    
                    if (imagem[i][j].equals("."))
                    {
                        anterior = ".";
                    } else
                    if (imagem[i][j].equals("*"))
                    {
                        anterior = "*";
                    }
                }
            }
            
            System.out.println("S");
            
        }
        catch (Exception e)
        {
            System.out.println(e);
        }
    }
}
