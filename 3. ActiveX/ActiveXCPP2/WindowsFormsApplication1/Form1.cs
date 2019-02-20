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

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
       float k;
        public Form1()
        {
            InitializeComponent();
            AxActiveXCPP22 axActiveXCPP22 = new AxActiveXCPP22();
            axActiveXCPP22.CreateControl();
                k = axActiveXCPP22.TestMyMethod(4, 4, "Hi");
        }

        private void button1_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Active returned:" + k);
        }
      
    }
}
