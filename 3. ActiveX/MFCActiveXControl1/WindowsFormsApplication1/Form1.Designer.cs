﻿namespace WindowsFormsApplication1
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
            this.axMFCActiveXControl11 = new AxMFCActiveXControl1Lib.AxMFCActiveXControl1();
            ((System.ComponentModel.ISupportInitialize)(this.axMFCActiveXControl11)).BeginInit();
            this.SuspendLayout();
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(48, 155);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(119, 67);
            this.button1.TabIndex = 0;
            this.button1.Text = "button1";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // axMFCActiveXControl11
            // 
            this.axMFCActiveXControl11.Enabled = true;
            this.axMFCActiveXControl11.Location = new System.Drawing.Point(48, 12);
            this.axMFCActiveXControl11.Name = "axMFCActiveXControl11";
            this.axMFCActiveXControl11.OcxState = ((System.Windows.Forms.AxHost.State)(resources.GetObject("axMFCActiveXControl11.OcxState")));
            this.axMFCActiveXControl11.Size = new System.Drawing.Size(166, 86);
            this.axMFCActiveXControl11.TabIndex = 1;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 261);
            this.Controls.Add(this.axMFCActiveXControl11);
            this.Controls.Add(this.button1);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.axMFCActiveXControl11)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button button1;
        private AxMFCActiveXControl1Lib.AxMFCActiveXControl1 axMFCActiveXControl11;
    }
}

