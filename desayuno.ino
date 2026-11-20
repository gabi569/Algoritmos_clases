using System;
using System.Collections.Generic;

namespace DesayunoEnClase
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Title = "Programa: Desayuno en Clase";
            bool continuar = true;

            while (continuar)
            {
                Console.Clear();
                Console.ForegroundColor = ConsoleColor.Yellow;
                Console.WriteLine("==================================================");
                Console.WriteLine("        PROGRAMA DE DESAYUNO EN CLASE        ");
                Console.WriteLine("==================================================");
                Console.ResetColor();

                Console.Write("\nIngrese la cantidad de participantes en el aula: ");
                if (!int.TryParse(Console.ReadLine(), out int alumnos) || alumnos <= 0)
                {
                    Console.WriteLine("\n Por favor, ingrese un número válido mayor a 0.");
                    Console.ReadKey();
                    continue;
                }

                Console.WriteLine("\nSeleccione el menú del desayuno:");
                Console.WriteLine("1. Clásico (Café con leche y medialunas)");
                Console.WriteLine("2. Saludable (Jugo de naranja, tostadas y frutas)");
                Console.WriteLine("3. Completo (Chocolatada, sándwiches y budín)");
                Console.Write("\nOpción elegida (1-3): ");
                string opcion = Console.ReadLine();

                Console.Clear();
                MostrarPlanDePreparacion(opcion, alumnos);

                Console.Write("\n¿Desea organizar otro desayuno? (S/N): ");
                string respuesta = Console.ReadLine()?.Trim().ToUpper();
                if (respuesta != "S")
                {
                    continuar = false;
                }
            }

            Console.WriteLine("\n¡Buen provecho y excelente jornada de clases!");
        }

        static void MostrarPlanDePreparacion(string opcion, int cantidad)
        {
            string nombreMenu = "";
            List<string> ingredientes = new List<string>();
            List<string> pasos = new List<string>();

            switch (opcion)
            {
                case "1":
                    nombreMenu = "Desayuno Clásico";
                    ingredientes.Add($"- {cantidad * 2} medialunas (dulces o saladas)");
                    ingredientes.Add($"- {Math.Ceiling(cantidad * 0.25)} litros de leche");
                    ingredientes.Add($"- {cantidad * 2} cucharaditas de café soluble o en saquitos");
                    ingredientes.Add($"- Azúcar / edulcorante y servilletas ({cantidad * 2} unidades)");

                    pasos.Add("1. Acomodar los bancos en mesa compartida y colocar manteles.");
                    pasos.Add("2. Calentar el agua y la leche (con supervisión docente).");
                    pasos.Add("3. Distribuir las tazas y servir las infusiones.");
                    pasos.Add("4. Repartir las medialunas en bandejas al centro.");
                    pasos.Add("5. Compartir el desayuno y luego limpiar el aula.");
                    break;

                case "2":
                    nombreMenu = "Desayuno Saludable";
                    ingredientes.Add($"- {Math.Ceiling(cantidad * 0.3)} litros de jugo de naranja natural");
                    ingredientes.Add($"- {cantidad * 2} rebanadas de pan integral tostado");
                    ingredientes.Add($"- {Math.Ceiling(cantidad / 4.0)} potes de queso untable / mermelada");
                    ingredientes.Add($"- {cantidad} frutas de estación (manzanas o bananas)");

                    pasos.Add("1. Lavar bien todas las frutas y cortarlas si es necesario.");
                    pasos.Add("2. Preparar las tostadas y disponer los untables con cuchillos plásticos.");
                    pasos.Add("3. Servir el jugo fresco en vasos individuales.");
                    pasos.Add("4. Armar los platos combinando tostadas y fruta.");
                    pasos.Add("5. Recoger residuos orgánicos y dejar el salón ordenado.");
                    break;

                case "3":
                    nombreMenu = "Desayuno Completo";
                    ingredientes.Add($"- {Math.Ceiling(cantidad * 0.25)} litros de leche chocolatada");
                    ingredientes.Add($"- {cantidad} sándwiches de jamón y queso");
                    ingredientes.Add($"- {Math.Ceiling(cantidad / 6.0)} budines cortados en rodajas");
                    ingredientes.Add($"- Servilletas y vasos descartables ({cantidad} unidades)");

                    pasos.Add("1. Organizar una mesa principal tipo buffet.");
                    pasos.Add("2. Disponer las bandejas con sándwiches y rodajas de budín.");
                    pasos.Add("3. Servir la chocolatada fría o tibia según el clima.");
                    pasos.Add("4. Realizar una breve ronda de bienvenida antes de comer.");
                    pasos.Add("5. Clasificar envases reciclables y limpiar las mesas.");
                    break;

                default:
                    Console.WriteLine(" Opción no válida. Se cargará el menú básico por defecto.");
                    nombreMenu = "Desayuno Básico";
                    ingredientes.Add($"- {cantidad} infusiones a elección");
                    ingredientes.Add($"- {cantidad * 3} galletitas surtidas");
                    pasos.Add("1. Preparar la mesa, servir y compartir en grupo.");
                    break;
            }

            Console.ForegroundColor = ConsoleColor.Cyan;
            Console.WriteLine($" PLANIFICACIÓN: {nombreMenu.ToUpper()} ({cantidad} personas)");
            Console.ResetColor();

            Console.WriteLine("\n LISTA DE INSUMOS NECESARIOS:");
            foreach (var item in ingredientes)
            {
                Console.WriteLine(item);
            }

            Console.WriteLine("\n ETAPAS DE REALIZACIÓN EN CLASE:");
            foreach (var paso in pasos)
            {
                Console.WriteLine(paso);
            }
        }
    }
}
