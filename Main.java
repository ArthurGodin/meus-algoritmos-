import java.util.Scanner;

public class Main
{
    public static void main(String[] args)
    {
        boolean continuar = true;

        while(continuar) {


            Scanner entrada = new Scanner(System.in);
            livro livro1 = new livro();
            livro livro2 = new livro();


            System.out.println("qual o título do livro ? ");
            livro1.titulo = entrada.nextLine();
            System.out.println("qual o nome do autor do livro ?");
            livro1.autor = entrada.nextLine();
            System.out.println("quantas páginas o livro possui ?");
            livro1.NumeroDePaginas = entrada.nextInt();
            entrada.nextLine();

            livro1.DetalheDosLivros();

            System.out.println("qual o título do segundo livro ? ");
            livro2.titulo = entrada.nextLine();
            System.out.println("qual o nome do autor do segundo livro ?");
            livro2.autor = entrada.nextLine();
            System.out.println("quantas páginas o segundo livro possui ?");
            livro2.NumeroDePaginas = entrada.nextInt();

            livro2.DetalheDosLivros();


            if (livro1.NumeroDePaginas < livro2.NumeroDePaginas) {
                System.out.println("este livro tem mais páginas que o livro passado\n");
                entrada.nextLine();
            }
            if (livro2.NumeroDePaginas < livro1.NumeroDePaginas) {
                System.out.println("este livro tem menos páginas que o livro passado\n");
                entrada.nextLine();
            }
            if (livro1.NumeroDePaginas == livro2.NumeroDePaginas) {
                System.out.println("o primeiro e o segundo livro tem as mesmas quantias de páginas.\n");
                entrada.nextLine();
            }
            System.out.println("quer fazer outra execução ? (s/n)");
            String resposta = entrada.nextLine();

            if (resposta.equals("s"))
            {
                continuar = true;
            }
            if (resposta.equals("n"))
            {
                
                continuar = false;
                System.out.println("obrigado pela preferência !");
            }
        }
    }
}

