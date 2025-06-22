namespace WindowsFormsApp1
{
    partial class Form6
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
            System.Windows.Forms.Label buildingLabel;
            System.Windows.Forms.Label flatLabel;
            System.Windows.Forms.Label streetLabel;
            this.buildingTextBox = new System.Windows.Forms.TextBox();
            this.flatTextBox = new System.Windows.Forms.TextBox();
            this.streetTextBox = new System.Windows.Forms.TextBox();
            this.adressBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            buildingLabel = new System.Windows.Forms.Label();
            flatLabel = new System.Windows.Forms.Label();
            streetLabel = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.adressBindingSource)).BeginInit();
            this.SuspendLayout();
            // 
            // buildingLabel
            // 
            buildingLabel.AutoSize = true;
            buildingLabel.Location = new System.Drawing.Point(20, 18);
            buildingLabel.Name = "buildingLabel";
            buildingLabel.Size = new System.Drawing.Size(73, 13);
            buildingLabel.TabIndex = 1;
            buildingLabel.Text = "Номер дома:";
            // 
            // buildingTextBox
            // 
            this.buildingTextBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.adressBindingSource, "Building", true));
            this.buildingTextBox.Location = new System.Drawing.Point(122, 15);
            this.buildingTextBox.Name = "buildingTextBox";
            this.buildingTextBox.Size = new System.Drawing.Size(184, 20);
            this.buildingTextBox.TabIndex = 2;
            // 
            // flatLabel
            // 
            flatLabel.AutoSize = true;
            flatLabel.Location = new System.Drawing.Point(20, 44);
            flatLabel.Name = "flatLabel";
            flatLabel.Size = new System.Drawing.Size(96, 13);
            flatLabel.TabIndex = 3;
            flatLabel.Text = "Номер квартиры:";
            // 
            // flatTextBox
            // 
            this.flatTextBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.adressBindingSource, "Flat", true));
            this.flatTextBox.Location = new System.Drawing.Point(122, 41);
            this.flatTextBox.Name = "flatTextBox";
            this.flatTextBox.Size = new System.Drawing.Size(184, 20);
            this.flatTextBox.TabIndex = 4;
            // 
            // streetLabel
            // 
            streetLabel.AutoSize = true;
            streetLabel.Location = new System.Drawing.Point(20, 70);
            streetLabel.Name = "streetLabel";
            streetLabel.Size = new System.Drawing.Size(42, 13);
            streetLabel.TabIndex = 5;
            streetLabel.Text = "Улица:";
            // 
            // streetTextBox
            // 
            this.streetTextBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.adressBindingSource, "Street", true));
            this.streetTextBox.Location = new System.Drawing.Point(122, 67);
            this.streetTextBox.Name = "streetTextBox";
            this.streetTextBox.Size = new System.Drawing.Size(184, 20);
            this.streetTextBox.TabIndex = 6;
            // 
            // adressBindingSource
            // 
            this.adressBindingSource.DataSource = typeof(WindowsFormsApp1.Adress);
            // 
            // button1
            // 
            this.button1.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.button1.Location = new System.Drawing.Point(23, 130);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 7;
            this.button1.Text = "Ok";
            this.button1.UseVisualStyleBackColor = true;
            // 
            // button2
            // 
            this.button2.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.button2.Location = new System.Drawing.Point(231, 130);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(75, 23);
            this.button2.TabIndex = 8;
            this.button2.Text = "Cancel";
            this.button2.UseVisualStyleBackColor = true;
            // 
            // Form6
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Controls.Add(buildingLabel);
            this.Controls.Add(this.buildingTextBox);
            this.Controls.Add(flatLabel);
            this.Controls.Add(this.flatTextBox);
            this.Controls.Add(streetLabel);
            this.Controls.Add(this.streetTextBox);
            this.Name = "Form6";
            this.Text = "Form6";
            ((System.ComponentModel.ISupportInitialize)(this.adressBindingSource)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.BindingSource adressBindingSource;
        private System.Windows.Forms.TextBox buildingTextBox;
        private System.Windows.Forms.TextBox flatTextBox;
        private System.Windows.Forms.TextBox streetTextBox;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
    }
}