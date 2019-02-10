using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace ErrorCheckStudentInfo
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void validateDataButton_Click(object sender, EventArgs e)
        {
            string name, classID, itemDescrip, errorMsg;
            double itemScore;
            int semesterStanding = 1;

            StreamReader inputFile;
            if (File.Exists("StudentsInfo.txt"))
            {
                //StudentChecker sc = new StudentChecker();
                StudentChecker sc = new StudentChecker(0, 120);
                inputFile = File.OpenText("StudentsInfo.txt");
                while (!inputFile.EndOfStream)
                {
                    //Input
                    name = inputFile.ReadLine();
                    classID = inputFile.ReadLine();
                    itemDescrip = inputFile.ReadLine();
                    semesterStanding = int.Parse(inputFile.ReadLine());
                    itemScore = double.Parse(inputFile.ReadLine());

                    //Error Checking
                    if (!sc.CheckSemesterStanding(semesterStanding)
                    {
                        errorMsg = String.Format("Error: semesterStanding --> {0} - {1} - {2} - {3} - {4}",
                            name, classID, itemDescrip, semesterStanding, itemScore);
                        msgListBox.Items.Add(errorMsg);
                    }
                    if (!sc.CheckScore(itemScore))
                    {
                        // The {0} are argument indices for items
                        errorMsg = String.Format("Error: ItemScore --> {0} - {1} - {2} - {3} - {4}",
                            name, classID, itemDescrip, semesterStanding, itemScore);
                        msgListBox.Items.Add(errorMsg);
                    }
                }
                inputFile.Close();
            }
            else
            {
                MessageBox.Show("Error. File does not exist");
            }
        }
    }
}
