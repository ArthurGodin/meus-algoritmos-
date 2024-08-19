import java.util.Scanner;

public class calcular_fatorial
{
    public static void main(String[] args)
    {
        boolean continuar = true;
        Scanner numero = new Scanner(System.in);
        Scanner resposta = new Scanner(System.in);

        while (continuar)
        {
            System.out.println("-- calculador de fatorial --");
            System.out.println("digite o número á se calcular o fatorial : \n");
            int num = numero.nextInt();

            long fatorial = 1;
            for (int i = 1; i <= num; i++) {
                fatorial *= i;
            }

            System.out.println("O fatorial de " + num + " é: " + fatorial);

            System.out.println("digite o número 1 para refazer o cálculo \n ");
            System.out.println("digite qualquer número diferente de 1 para sair \n");
            int opcao = resposta.nextInt();

            if (opcao != 1)
            {
                System.out.println("obrigado pela preferência! :) ");
                continuar = false;
            }

        }
        numero.close();
    }
}