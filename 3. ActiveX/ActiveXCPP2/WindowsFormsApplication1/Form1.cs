using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using ActiveXCPP22Lib;            //не забудьте добавить строки подключения
using AxActiveXCPP22Lib;
using AxMFCActiveXControl1Lib;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
       int n;
        public Form1()
        {
            InitializeComponent();
           
              
            n = axMFCActiveXControl11.TestMyMethod(5, 4, "Hi");

        }

        private void button1_Click(object sender, EventArgs e)
        {
            
            MessageBox.Show("Active returned:" + n);

        }

    }
}
