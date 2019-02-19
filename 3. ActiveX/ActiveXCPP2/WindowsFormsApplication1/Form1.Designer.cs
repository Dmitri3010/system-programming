namespace WindowsFormsApplication1
{
    partial class Form1
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.button1 = new System.Windows.Forms.Button();
            this.axActiveXCPP221 = new AxActiveXCPP22Lib.AxActiveXCPP22();
            ((System.ComponentModel.ISupportInitialize)(this.axActiveXCPP221)).BeginInit();
            this.SuspendLayout();
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(159, 188);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(123, 58);
            this.button1.TabIndex = 0;
            this.button1.Text = "button1";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // axActiveXCPP221
            // 
            this.axActiveXCPP221.Enabled = true;
            this.axActiveXCPP221.Location = new System.Drawing.Point(306, 27);
            this.axActiveXCPP221.Name = "axActiveXCPP221";
            this.axActiveXCPP221.OcxState = ((System.Windows.Forms.AxHost.State)(resources.GetObject("axActiveXCPP221.OcxState")));
            this.axActiveXCPP221.Size = new System.Drawing.Size(111, 80);
            this.axActiveXCPP221.TabIndex = 1;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(427, 295);
            this.Controls.Add(this.axActiveXCPP221);
            this.Controls.Add(this.button1);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.axActiveXCPP221)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button button1;
        private AxActiveXCPP22Lib.AxActiveXCPP22 axActiveXCPP221;
    }
}

