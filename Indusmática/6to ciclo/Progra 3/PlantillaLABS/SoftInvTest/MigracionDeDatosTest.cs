using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using Business;
using Model;

namespace SoftInvTest
{
    [TestClass]
    public class MigracionDeDatosTest
    {
        private MigracionDeDatos migracionDeDatos;

        public MigracionDeDatosTest()
        {
            this.migracionDeDatos = new MigracionDeDatos();
        }

        [TestMethod]
        public void TestMigracionDeDatos()
        {
            Console.WriteLine("EjecutarMigracion");
            int result = this.migracionDeDatos.EjecutarMigracion();
            Assert.IsTrue(result > 0);
        }
    }
}
