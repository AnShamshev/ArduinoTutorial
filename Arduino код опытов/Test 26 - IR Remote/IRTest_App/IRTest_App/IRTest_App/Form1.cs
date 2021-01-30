using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;
using System.Threading;

namespace IRTest_App
{
    public partial class Form1 : Form
    {
        public SerialPort ComPort { get; private set; }

        public Form1()
        {
            InitializeComponent();
            listBox1.Items.Clear();
            ComPort = new SerialPort("COM4", 9600);
            ComPort.DataReceived += ComPort_DataReceived;
            ComPort.Open();
        }

        private delegate void SetTextDeleg(string text);

        private void si_DataReceived(string data)
        {
            string temp=data.Trim();
            listBox1.Items.Add(temp);
        }

        private void ComPort_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            Thread.Sleep(500);
            string data = ComPort.ReadLine();
            // Привлечение делегата на потоке UI, и отправка данных, которые
            // были приняты привлеченным методом.
            // ---- Метод "si_DataReceived" будет выполнен в потоке UI,
            // который позволит заполнить текстовое поле TextBox.
            this.BeginInvoke(new SetTextDeleg(si_DataReceived),
                             new object[] { data });            
            //MessageBox.Show(((SerialPort)sender).ReadLine().ToString());
        }
    }
}
