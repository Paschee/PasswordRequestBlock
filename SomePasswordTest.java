import javax.swing.*;
import java.awt.*;
import java.io.*;
import java.awt.event.*;
// import java.util.Scanner; - War ursprünglich für eine Textbasierte Version gedacht *

//------------------------------------------------------

public class SomePasswordTest extends JFrame {
  
	// Oberfläche
	static JPanel PW = new JPanel();
	static JPasswordField Kennwort = new JPasswordField(10);
	static JButton Abbruch = new JButton("Abbruch");
	static JButton Klartext = new JButton("Klartext");
	static JButton Speichern = new JButton("Speichern");
	static JButton Verschlüsseln = new JButton("Verschlüsseln");

	// FileHandling
	static File file;
	static FileWriter writer;
	
	// StringStuff
	static String P1 = Kennwort.toString(); // Macht nicht das was ich gern hätte.
	
	
	public static void main(String[] args) throws IOException {
		SomePasswordTest SomePasswordTest = new SomePasswordTest();
	 }
	
	
	 public static void centreWindow(Window frame) 
	 {
		 Dimension dimension = Toolkit.getDefaultToolkit().getScreenSize();
		 int x = (int) ((dimension.getWidth() - frame.getWidth()) / 2);
		 int y = (int) ((dimension.getHeight() - frame.getHeight()) / 2);
		 frame.setLocation(x, y);
	 }
	 
	 public SomePasswordTest() {
		super("SomePasswordTest");
		
		 
		Speichern.setEnabled(true);
		Klartext.setEnabled(true);
		Abbruch.setEnabled(true);
		
		Kennwort.setEchoChar('•');
		PW.add(Kennwort);
		setContentPane(PW);
		
		Speichern.addActionListener(new ActionListener() {

	        public void actionPerformed(ActionEvent e) {
	            Safe();
	        }
	    });
	 
		Klartext.addActionListener(new ActionListener() {
			
			public void actionPerformed(ActionEvent e) {
				Readable();
			}
		});
		
		Abbruch.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				Cancel();
			}
		});
		
		Verschlüsseln.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				Crypt();
			}
		});
		
	 setLayout(new FlowLayout());
	 
	 
	 add(Speichern);
	 add(Klartext);
	 add(Abbruch);
	 add(Verschlüsseln);
	 
	 setSize(530,80);
	 centreWindow(SomePasswordTest.this);
	    setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);

	    
	    setVisible(true);

	 
	 
	 }
	 
	/* Wird in .txt gespeichert */ 
	public static void Safe () {
		file = new File("Password.txt");
		
		try {
			writer = new FileWriter(file ,true);
			
			writer.write(P1);
			writer.write("Hallo"); // Ist nur Testweise.
			
			writer.flush();
			writer.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		System.exit(0);
	}
	
	/* Verschlüsselung aufheben */
	public static void Readable() {
		Kennwort.getPassword();
	}
	
	public static void Cancel() {
		System.exit(0);
	}
	
	public static void Crypt() {
		
	}
}
