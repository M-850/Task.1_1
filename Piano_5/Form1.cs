using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Threading;
namespace Piano_1
{
    public partial class Form1 : Form
    {
        Bitmap piano;// изобразжения клавиш первой актавы
        Bitmap note;//изображение нот
        int all_note;//колчичество изображений нот на уровне
        double percent_true;//процент правильных нажатий
        int level_pointer;//количество очков 
        Color c;//цвет пикселя
        List<Note> notes = new List<Note>();//список нот
        Random random_note;//случайного числа
        int i;//номер случайной ноты
        int pointer;//количество правильных ответов
        int pointer_no;//количество неправильных ответов
        public Form1()
        {
            InitializeComponent();
            label1.Text = "Парвильных нажатий:";
            label2.Text = "Не правильных нажатий:";
            label6.Text = "";
            button3.Enabled = false;
            button4.Enabled = false;
            this.pointer = 0;
            this.pointer_no = 0;
            label7.Text = pointer.ToString(); 
            label8.Text = pointer_no.ToString();
            label9.Text = "";

        }

        private void PictureBox2_Click(object sender, EventArgs e)
        {
   
        }

        private void Button1_Click(object sender, EventArgs e)
        {
            percent_true = 0;
            pictureBox2.Enabled = true;
            pointer = 0;
            pointer_no = 0;
            label7.Text = pointer.ToString();
            label8.Text = pointer_no.ToString();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            level_pointer = 10;
           
            piano = new Bitmap("Piano_keys_1.bmp");
            pictureBox2.Image = piano;
            notes.Add(new Note("The_first_octave_С.gif", "Piano_keys_C_true.bmp", "Piano_keys_C_false.bmp", "До", 255, 255, 255));
            notes.Add(new Note("The_first_octave_D.gif", "Piano_keys_D_true.bmp", "Piano_keys_D_false.bmp", "Ре", 255, 255, 254));
            notes.Add(new Note("The_first_octave_E.gif", "Piano_keys_E_true.bmp", "Piano_keys_E_false.bmp", "Ми", 255, 254, 255));
            notes.Add(new Note("The_first_octave_F.gif", "Piano_keys_F_true.bmp", "Piano_keys_F_false.bmp", "Фа", 255, 254, 254));
            notes.Add(new Note("The_first_octave_G.gif", "Piano_keys_G_true.bmp", "Piano_keys_G_false.bmp", "Соль", 254, 255, 255));
            notes.Add(new Note("The_first_octave_A.gif", "Piano_keys_A_true.bmp", "Piano_keys_A_false.bmp", "Ля", 254, 255, 254));
            notes.Add(new Note("The_first_octave_B.gif", "Piano_keys_B_true.bmp", "Piano_keys_B_false.bmp", "Си", 254, 254, 255));
            all_note = 7;
            random_note = new Random();
            i = random_note.Next(0, all_note);
            pictureBox1.Image = notes[i].img_note;
        }

        private void Label2_Click(object sender, EventArgs e)
        {
          
        }

        private void PictureBox2_MouseClick(object sender, MouseEventArgs e)
        {
            pictureBox2.Image = piano;
            label1.Text = "Парвильных нажатий:";
            label2.Text = "Не правильных нажатий:";
           
                c = piano.GetPixel(e.X, e.Y);
                if (c.R == notes[i].R && c.G == notes[i].G && c.B == notes[i].B)
                {
                pointer++;
                label7.Text = pointer.ToString();
                label6.Text = "Нажата " + notes[i].name;
                pictureBox2.Image = notes[i].img_piano_note_true;
                random_note = new Random();
                i = random_note.Next(0, all_note);
                pictureBox1.Image = notes[i].img_note;
                }
               
                else
                {
                pointer_no++;
                label6.Text = "Вы выбрали не правильно ноту";
                label8.Text = pointer_no.ToString();
                for(int j = 0; j < all_note; j++)
                {
                    if(notes[j].R==c.R && notes[j].B == c.B && notes[j].G == c.G)
                    {
                       pictureBox2.Image = notes[j].img_piano_note_false;
                    }
                }
            }
                if(pointer == level_pointer)
            { 
                percent_true = 100 * (double)pointer / (double)(pointer + pointer_no);
                label9.Text = "Процент правильных нажатий:" + percent_true.ToString() + "%";
                if(percent_true >= 90)
                {   if (level_pointer == 10)
                    {
                        button3.Enabled = true;
                    }
                else if(level_pointer == 15)
                    {
                        button4.Enabled = true;
                    }
                }
                pictureBox2.Enabled = false;
            }
        }

        private void Label6_Click(object sender, EventArgs e)
        {

        }

        private void Label5_Click(object sender, EventArgs e)
        {

        }

        private void Label7_Click(object sender, EventArgs e)
        {
            
        }

        private void Button2_Click(object sender, EventArgs e)
        {
            level_pointer = 10;
            pictureBox2.Image = piano;
            pointer = 0;
            pointer_no = 0;
            label7.Text = pointer.ToString();
            label8.Text = pointer_no.ToString();
            notes = new List<Note>();
            notes.Add(new Note("The_first_octave_С.gif", "Piano_keys_C_true.bmp", "Piano_keys_C_false.bmp", "До", 255, 255, 255));
            notes.Add(new Note("The_first_octave_D.gif", "Piano_keys_D_true.bmp", "Piano_keys_D_false.bmp", "Ре", 255, 255, 254));
            notes.Add(new Note("The_first_octave_E.gif", "Piano_keys_E_true.bmp", "Piano_keys_E_false.bmp", "Ми", 255, 254, 255));
            notes.Add(new Note("The_first_octave_F.gif", "Piano_keys_F_true.bmp", "Piano_keys_F_false.bmp", "Фа", 255, 254, 254));
            notes.Add(new Note("The_first_octave_G.gif", "Piano_keys_G_true.bmp", "Piano_keys_G_false.bmp", "Соль", 254, 255, 255));
            notes.Add(new Note("The_first_octave_A.gif", "Piano_keys_A_true.bmp", "Piano_keys_A_false.bmp", "Ля", 254, 255, 254));
            notes.Add(new Note("The_first_octave_B.gif", "Piano_keys_B_true.bmp", "Piano_keys_B_false.bmp", "Си", 254, 254, 255));
            all_note = 7;
            random_note = new Random();
            i = random_note.Next(0, all_note);
            pictureBox1.Image = notes[i].img_note;
        }

        private void Button3_Click(object sender, EventArgs e)
        {
            level_pointer = 15;
            pictureBox2.Enabled = true;
            pictureBox2.Image = piano;
            pointer = 0;
            pointer_no = 0;
            percent_true = 0;
            label9.Text = "";
            label7.Text = pointer.ToString();
            label8.Text = pointer_no.ToString();
            notes = new List<Note>();
            notes.Add(new Note("The_first_octave_С_level_2.png", "Piano_keys_C_true.bmp", "Piano_keys_C_false.bmp", "До", 255, 255, 255));
            notes.Add(new Note("The_first_octave_#_С_level_2.png", "Piano_keys_#_C_true.bmp", "Piano_keys_#_C_false.bmp", "Диез-До", 0, 0, 0));
            notes.Add(new Note("The_first_octave_D_level_2.png", "Piano_keys_D_true.bmp", "Piano_keys_D_false.bmp", "Ре", 255, 255, 254));
            notes.Add(new Note("The_first_octave_#_D_level_2.png", "Piano_keys_#_D_true.bmp", "Piano_keys_#_D_false.bmp", "Диез-Ре", 0, 0, 1));
            notes.Add(new Note("The_first_octave_E_level_2.png", "Piano_keys_E_true.bmp", "Piano_keys_E_false.bmp", "Ми", 255, 254, 255));
            notes.Add(new Note("The_first_octave_F_level_2.png", "Piano_keys_F_true.bmp", "Piano_keys_F_false.bmp", "Фа", 255, 254, 254));
            notes.Add(new Note("The_first_octave_#_F_level_2.png", "Piano_keys_#_F_true.bmp", "Piano_keys_#_F_false.bmp", "Диез-Фа", 0, 1, 0));
            notes.Add(new Note("The_first_octave_G_level_2.png", "Piano_keys_G_true.bmp", "Piano_keys_G_false.bmp", "Соль", 254, 255, 255));
            notes.Add(new Note("The_first_octave_#_G_level_2.png", "Piano_keys_#_G_true.bmp", "Piano_keys_#_G_false.bmp", "Диез-Соль", 0, 1, 1));
            notes.Add(new Note("The_first_octave_A_level_2.png", "Piano_keys_A_true.bmp", "Piano_keys_A_false.bmp", "Ля", 254, 255, 254));
            notes.Add(new Note("The_first_octave_#_A_level_2.png", "Piano_keys_#_A_true.bmp", "Piano_keys_#_A_false.bmp", "Диез-Ля", 1, 0, 0));
            notes.Add(new Note("The_first_octave_B_level_2.png", "Piano_keys_B_true.bmp", "Piano_keys_B_false.bmp", "Си", 254, 254, 255));
            all_note = 12;
            random_note = new Random();
            i = random_note.Next(0, all_note);
            pictureBox1.Image = notes[i].img_note;
        }

        private void Button4_Click(object sender, EventArgs e)
        {
            level_pointer = 20;
            pictureBox2.Enabled = true;
            pictureBox2.Image = piano;
            pointer = 0;
            pointer_no = 0;
            percent_true = 0;
            label9.Text = "";
            label7.Text = pointer.ToString();
            label8.Text = pointer_no.ToString();
            notes.Add(new Note("The_first_octave_b_D_level_3.png", "Piano_keys_#_C_true.bmp", "Piano_keys_#_C_false.bmp", "Бемоль-Ре", 0, 0, 0));
            notes.Add(new Note("The_first_octave_b_E_level_3.png", "Piano_keys_#_D_true.bmp", "Piano_keys_#_D_false.bmp", "Бемоль-Ми", 0, 0, 1));
            notes.Add(new Note("The_first_octave_b_G_level_3.png", "Piano_keys_#_F_true.bmp", "Piano_keys_#_F_false.bmp", "Бемоль-Соль", 0, 1, 0));
            notes.Add(new Note("The_first_octave_b_A_level_3.png", "Piano_keys_#_G_true.bmp", "Piano_keys_#_G_false.bmp", "Бемоль-Ля", 0, 1, 1));
            notes.Add(new Note("The_first_octave_b_B_level_3.png", "Piano_keys_#_A_true.bmp", "Piano_keys_#_A_false.bmp", "Бемоль-Си", 1, 0, 0));
            all_note = 17;
            random_note = new Random();
            i = random_note.Next(0, all_note);
            pictureBox1.Image = notes[i].img_note;

        }

        private void Label8_Click(object sender, EventArgs e)
        {

        }
    }
    public class Note
    {
        public Bitmap img_note;//изображение ноты
        public Bitmap img_piano_note_true;//изображение клавиш первой октавы при правлильном нажатии данной ноты
        public Bitmap img_piano_note_false;//изображение клавиш первой октавы при неправильном нажатии данной ноты
        public string name;// название ноты
        public int R;//красная состовляющяя 
        public int G;//зелённая состовляющая
        public int B;//синия состовляющая
        public Note(string bmp_file_name,string bmp_piano_note_true, string bmp_piano_note_false, string name, int R, int G, int B)
       {
            this.R = R;
            this.G = G;
            this.B = B;
            this.name = name;
            img_note = new Bitmap(bmp_file_name);
            img_piano_note_true = new Bitmap(bmp_piano_note_true);
            img_piano_note_false = new Bitmap(bmp_piano_note_false);  
       }
    }
}
