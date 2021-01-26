using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.IO.Ports;

namespace Manual_Led_Test
{
    /// <summary>
    /// Логика взаимодействия для MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        SerialPort ComPort;
        public MainWindow()
        {
            InitializeComponent();
            ComPort = new SerialPort("COM4",9600);
            ComPort.WriteTimeout = 500;
            ComPort.ReadTimeout = 500;
            ComPort.Open();
            //Сброс начальных значений
            ComPort.WriteLine("0,0,0");
            ComPort.Close();
        }

        private void Slider_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            ComPort.Open();
            if (ComPort.IsOpen)
            {
                string temp;
                temp = Convert.ToString(RSlider.Value) + ',' + Convert.ToString(GSlider.Value) + ',' + Convert.ToString(BSlider.Value);            
                ComPort.WriteLine(temp);
                ComPort.Close();
            }
        }

        private void GSlider_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            ComPort.Open();
            if (ComPort.IsOpen)
            {
                string temp;
                temp = Convert.ToString(RSlider.Value) + ',' + Convert.ToString(GSlider.Value) + ',' + Convert.ToString(BSlider.Value);
                ComPort.WriteLine(temp);
                ComPort.Close();

            }

        }

        private void BSlider_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            ComPort.Open();
            if (ComPort.IsOpen)
            {
                string temp;
                temp = Convert.ToString(RSlider.Value) + ',' + Convert.ToString(GSlider.Value) + ',' + Convert.ToString(BSlider.Value);
                ComPort.WriteLine(temp);
                ComPort.Close();

            }

        }
    }
}
