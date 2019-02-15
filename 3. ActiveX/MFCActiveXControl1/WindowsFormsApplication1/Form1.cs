using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using MFCActiveXControl1Lib;
using AxMFCActiveXControl1Lib;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        static int k = 10;
        public Form1()
        {
            InitializeComponent();
            k = axMFCActiveXControl11.TestMyMethod(5, 4, "Hi");
            axMFCActiveXControl11.EventHandlerTest += new AxMFCActiveXControl1Lib._DMFCActiveXControl1Events_EventHandlerTestEventHandler(axMFCActiveXControl11_EventHandlerTest);
        }

        private void axMFCActiveXControl11_EventHandlerTest(object sender, _DMFCActiveXControl1Events_EventHandlerTestEvent e)
        {
            int age = e.age;
            string name = e.name;
            string surname = e.surname;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Active returned: "+k);
        }
    }
}
