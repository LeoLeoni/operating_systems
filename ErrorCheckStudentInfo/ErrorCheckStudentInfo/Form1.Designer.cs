namespace ErrorCheckStudentInfo
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.validateDataButton = new System.Windows.Forms.Button();
            this.msgListBox = new System.Windows.Forms.ListBox();
            this.SuspendLayout();
            // 
            // validateDataButton
            // 
            this.validateDataButton.Location = new System.Drawing.Point(12, 12);
            this.validateDataButton.Name = "validateDataButton";
            this.validateDataButton.Size = new System.Drawing.Size(75, 39);
            this.validateDataButton.TabIndex = 0;
            this.validateDataButton.Text = "Validate Data";
            this.validateDataButton.UseVisualStyleBackColor = true;
            this.validateDataButton.Click += new System.EventHandler(this.validateDataButton_Click);
            // 
            // msgListBox
            // 
            this.msgListBox.FormattingEnabled = true;
            this.msgListBox.Location = new System.Drawing.Point(12, 59);
            this.msgListBox.Name = "msgListBox";
            this.msgListBox.Size = new System.Drawing.Size(468, 212);
            this.msgListBox.TabIndex = 1;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(492, 283);
            this.Controls.Add(this.msgListBox);
            this.Controls.Add(this.validateDataButton);
            this.Name = "Form1";
            this.Text = "Check Student Data";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button validateDataButton;
        private System.Windows.Forms.ListBox msgListBox;
    }
}

