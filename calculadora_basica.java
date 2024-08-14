import java.util.Scanner;

public class calculadora_basica
{
    public static void main(String[] args)
    {
        boolean continuar = true;
        Scanner entrada = new Scanner(System.in);

        while (continuar)
        {
            System.out.println("--calculadora besta--");
            System.out.println("Digite o primeiro numero: ");
            float numero1 = entrada.nextFloat();
            System.out.println("Digite o segundo numero: ");

            float numero2 = entrada.nextFloat();
            System.out.println("escolha a operação à executar");
            System.out.println("1 - soma\n");
            System.out.println("2 - subtração\n");
            System.out.println("3 - multiplicação\n");
            System.out.println("4 - divisão\n");
            int escolha = entrada.nextInt();

            if (escolha == 1)
            {
                float soma = numero1 + numero2;
                System.out.printf("%.2f + %.2f = %.2f\n", numero1, numero2, soma);
            }
            else if (escolha == 2)
            {
                float subtracao = numero1 - numero2;
                System.out.printf("%.2f - %.2f = %.2f\n", numero1, numero2, subtracao);
            }
            else if (escolha == 3)
            {
                float multi = numero1 * numero2;
                System.out.printf("%.2f * %.2f = %.2f\n", numero1, numero2, multi);
            }
            else if (escolha == 4)
            {
                if (numero1 <= 0)
                {
                    System.out.println("o número não pode ter divisão");
                }
                else
                {
                    float divisao = numero1 / numero2;
                    System.out.printf("%.2f dividido por %.2f = %.2f\n", numero1, numero2, divisao);
                }
            }
            else
            {
                System.out.println("essa opção é inválida.");
            }


            System.out.println("1 para refazer outra soma, qualquer outro número para sair:");
            int resposta = entrada.nextInt();

            if (resposta != 1)
            {
                System.out.println("obrigado pela preferência!");
                continuar = false;
            }
        }

        entrada.close();
    }
}
