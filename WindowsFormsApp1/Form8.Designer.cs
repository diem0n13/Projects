namespace WindowsFormsApp1
{
    partial class Form8
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
            this.components = new System.ComponentModel.Container();
            System.Windows.Forms.Label kindPhoneLabel;
            System.Windows.Forms.Label phoneNumberLabel;
            this.phoneBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.kindPhoneTextBox = new System.Windows.Forms.TextBox();
            this.phoneNumberTextBox = new System.Windows.Forms.TextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            kindPhoneLabel = new System.Windows.Forms.Label();
            phoneNumberLabel = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.phoneBindingSource)).BeginInit();
            this.SuspendLayout();
            // 
            // phoneBindingSource
            // 
            this.phoneBindingSource.DataSource = typeof(WindowsFormsApp1.Phone);
            // 
            // kindPhoneLabel
            // 
            kindPhoneLabel.AutoSize = true;
            kindPhoneLabel.Location = new System.Drawing.Point(253, 44);
            kindPhoneLabel.Name = "kindPhoneLabel";
            kindPhoneLabel.Size = new System.Drawing.Size(81, 13);
            kindPhoneLabel.TabIndex = 1;
            kindPhoneLabel.Text = "Тип телефона:";
            // 
            // kindPhoneTextBox
            // 
            this.kindPhoneTextBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.phoneBindingSource, "KindPhone", true));
            this.kindPhoneTextBox.Location = new System.Drawing.Point(355, 41);
            this.kindPhoneTextBox.Name = "kindPhoneTextBox";
            this.kindPhoneTextBox.Size = new System.Drawing.Size(147, 20);
            this.kindPhoneTextBox.TabIndex = 2;
            // 
            // phoneNumberLabel
            // 
            phoneNumberLabel.AutoSize = true;
            phoneNumberLabel.Location = new System.Drawing.Point(253, 70);
            phoneNumberLabel.Name = "phoneNumberLabel";
            phoneNumberLabel.Size = new System.Drawing.Size(96, 13);
            phoneNumberLabel.TabIndex = 3;
            phoneNumberLabel.Text = "Номер телефона:";
            // 
            // phoneNumberTextBox
            // 
            this.phoneNumberTextBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.phoneBindingSource, "PhoneNumber", true));
            this.phoneNumberTextBox.Location = new System.Drawing.Point(355, 67);
            this.phoneNumberTextBox.Name = "phoneNumberTextBox";
            this.phoneNumberTextBox.Size = new System.Drawing.Size(147, 20);
            this.phoneNumberTextBox.TabIndex = 4;
            // 
            // button1
            // 
            this.button1.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.button1.Location = new System.Drawing.Point(259, 141);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 5;
            this.button1.Text = "Ok";
            this.button1.UseVisualStyleBackColor = true;
            // 
            // button2
            // 
            this.button2.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.button2.Location = new System.Drawing.Point(427, 141);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(75, 23);
            this.button2.TabIndex = 6;
            this.button2.Text = "Cancel";
            this.button2.UseVisualStyleBackColor = true;
            // 
            // Form8
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 234);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Controls.Add(kindPhoneLabel);
            this.Controls.Add(this.kindPhoneTextBox);
            this.Controls.Add(phoneNumberLabel);
            this.Controls.Add(this.phoneNumberTextBox);
            this.Name = "Form8";
            this.Text = "Form8";
            ((System.ComponentModel.ISupportInitialize)(this.phoneBindingSource)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.BindingSource phoneBindingSource;
        private System.Windows.Forms.TextBox kindPhoneTextBox;
        private System.Windows.Forms.TextBox phoneNumberTextBox;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
    }
}