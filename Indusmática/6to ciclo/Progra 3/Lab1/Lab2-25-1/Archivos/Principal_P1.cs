using System;

namespace Pregunta1
{
    public class Principal
    {
        static void Main(string[] args)
        {
            Postulante postulante = new Postulante();
            FichaEvaluacion ficha = new FichaEvaluacion();
            Admision admision = new Admision();

            postulante.Paterno = "Pérez";
            postulante.Materno = "Deza";
            postulante.Nombre = "Juan Alonso";
            postulante.Dni = "75355946B";
            ficha.Candidato = postulante;
            ficha.Fecha_hora = new DateTime(2025, 02, 20, 14, 00, 00);
            ficha.Evaluacion_expediente = 22;
            ficha.Evaluacion_entrevista = 47;
            ficha.Evaluacion_examen = 18;
            admision.agregarFichaDeEvaluacion(ficha);

            postulante.Paterno = "León";
            postulante.Materno = "Mendoza";
            postulante.Nombre = "Carmen";
            postulante.Dni = "87332141Z";
            ficha.Candidato = postulante;
            ficha.Fecha_hora = new DateTime(2025, 02, 20, 14, 30, 00);
            ficha.Evaluacion_expediente = 12;
            ficha.Evaluacion_entrevista = 22;
            ficha.Evaluacion_examen = 17;
            admision.agregarFichaDeEvaluacion(ficha);

            postulante.Paterno = "Sandoval";
            postulante.Materno = "García";
            postulante.Nombre = "Eric";
            postulante.Dni = "73734226K";
            ficha.Candidato = postulante;
            ficha.Fecha_hora = new DateTime(2025, 02, 20, 15, 00, 00);
            ficha.Evaluacion_expediente = 15;
            ficha.Evaluacion_entrevista = 45;
            ficha.Evaluacion_examen = 23;
            admision.agregarFichaDeEvaluacion(ficha);

            Console.WriteLine(admision);
        }
    }
}
