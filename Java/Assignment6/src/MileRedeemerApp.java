/**********************************************************
 *                                                        *
 *  CSCI 470/502        Assignment 6         Summer 2021  *
 *                                                        *
 *  Developer(s):  Anushka Verma                          *
 *                                                        *
 *  Section:  01                                          *
 *                                                        *
 *  Due Date/Time:  08/05/2021 11:59 PM                   *
 *                                                        *
 *  Purpose:  A Javafx GUI app to help a travel           *
 *            agent present travel destination options    *
 *            to clients.                                 *
 *                                                        *
 **********************************************************/

//Imports all the necessary Libraries
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx.scene.layout.HBox;
import javafx.stage.FileChooser;
import javafx.scene.Parent;
import java.util.Scanner;                                       //Imports Scanner library
import java.io.File;                                            //Imports IO library

public class MileRedeemerApp extends Application                                    //Creates the MileRedeemerApp class
{
    static MileRedeemer yourMiles = new MileRedeemer();
    public File fil;
    @Override
    public void start(Stage stage) throws Exception
    {
        FileChooser f = new FileChooser();                      //Creates a file chooser
        f.setTitle("Opening the location..");                   //Sets the title
        fil = f.showOpenDialog(stage);                          //Opens the dialogue box
        HBox r = new HBox();
        r.setSpacing(20);

        Scene sc = new Scene(r,350,100);           //Creates a scene
        stage.setScene(sc);                                     //Sets a scene
        stage.setTitle("Welcome To The Mile Redemption App");   //Sets the title
        stage.show();                                           //Display's the result
        yourMiles.readDestinations(new Scanner(fil));

        Parent root = FXMLLoader.load(getClass().getResource("MileRedeemer.fxml"));     //Loads the fxml file
        Scene sc1 = new Scene(root);
        stage.setScene(sc1);
        stage.setTitle("Welcome To The Mile Redemption App");
        stage.show();
    }

    public static void main(String[] args)   //Main method
    {
        launch(args);
    }
}
