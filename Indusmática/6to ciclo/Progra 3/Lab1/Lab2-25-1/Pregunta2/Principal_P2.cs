using System;

namespace Pregunta2
{
    public class Principal
    {
        static void Main(string[] args)
        {
            CancionBuilder cancionBuilder = new CancionBuilder();
            Cancion cancion = cancionBuilder
                .ConTitulo("Cuando estoy triste")
                .TambienConocidaComo("Cajita de música")
                .InterpretadoPor("Mercedes Sosa")
                .CompuestoPor("Jose Pedroni")                
                .CompuestoPor("Damián Sánchez")                
                .DelGenero(Genero.FOLKLORE)
                .EnElAlbum("A que florezca mi pueblo")
                .BuildCancion();
            Console.WriteLine(cancion);
            Console.WriteLine();

            cancion = new CancionBuilder()
                .ConTitulo("Sonata para violonchelo n.1 en fa mayor")
                .CompuestoPor("Ludwig van Beethoven")
                .DelGenero(Genero.CLASICA)
                .IdentificadoConOpus(5)
                .IdentificadoConSubOpus(1)
                .DedicadoA("Federico Guillermo II de Prusia")
                .BuildCancion();
            Console.WriteLine(cancion);
            Console.WriteLine();

            cancion = new CancionBuilder()
                .ConTitulo("Concierto para piano n.1 en do mayor")
                .CompuestoPor("Ludwig van Beethoven")
                .DelGenero(Genero.CLASICA)
                .IdentificadoConOpus(15)
                .DedicadoA("Princesa Barbara Odescalchi")
                .BuildCancion();
            Console.WriteLine(cancion);
            Console.WriteLine();
        }
    }
}
