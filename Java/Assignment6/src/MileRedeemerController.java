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

//Importing all the necessary libraries
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.ChoiceBox;
import javafx.scene.control.TextField;
import javafx.event.ActionEvent;
import javafx.scene.control.ListView;
import java.net.URL;
import java.util.ArrayList;
import java.util.ResourceBundle;
import java.util.List;
import java.util.Arrays;
import javafx.scene.input.MouseEvent;

public class MileRedeemerController implements Initializable
{
    MileRedeemer yMiles = MileRedeemerApp.yourMiles;    //Using my Mile Redeemer Package, it creates a variable
                                                        // which calls my Mile Redemption App
    List<String> cSpots = new ArrayList<String>(Arrays.asList(yMiles.getCityNames()));
    ObservableList<String> c = FXCollections.observableArrayList(cSpots);   //It automatically updates a list if any changes are made

    String[] mDeparture = {"January", "February", "March", "April", "May", "June", "July",
                            "August", "September", "October", "November", "December"};   //Stores the months in a mDeparture array
    List<String> monthD = new ArrayList<String>(Arrays.asList(mDeparture));
    ObservableList<String> mD = FXCollections.observableArrayList(monthD);

    //ChoiceBox, TextField, ListView Objects used in my GUI design
    @FXML
    private TextField normalMiles;

    @FXML
    private TextField supersSaveMiles;

    @FXML
    private TextField upgradeCost;

    @FXML
    private TextField superSaverDates;

    @FXML
    private ListView<String> destList;

    @FXML
    private TextField yourMiles;

    @FXML
    private ChoiceBox<String> monthDepart;

    @FXML
    private ListView<String> redeemList;

    @FXML
    private TextField remainingMiles;

    //The redeemMilesPressed method allows us to drop down our choice box to pick a month
    //and then it makes our RedeemMiles button active, which then it gives us a list of the destination spot and whether
    //the passenger upgraded or not. Or if the passenger doesn't have enough miles then it display's error message
    @FXML
    void redeemMilesPressed(ActionEvent event)
    {
        String miles = yourMiles.getText();
        int monPicker = monthDepart.getSelectionModel().getSelectedIndex()+1;
        String[] arr = yMiles.redeemMiles(Integer.parseInt(miles),monPicker);
        remainingMiles.setText(Integer.toString(yMiles.getRemainingMiles()));
        redeemList.setItems(FXCollections.observableArrayList(arr));
    }

    //The destSpot method allows us to click on the destination to view it's details
    @FXML
    void destSpot(MouseEvent event)
    {
        String desSpt = destList.getSelectionModel().getSelectedItem();
        Destination desVar = yMiles.getDDetails(desSpt);
        normalMiles.setText(Integer.toString(desVar.getMileage()));
        supersSaveMiles.setText(Integer.toString(desVar.getOffSeasonMileage()));
        upgradeCost.setText(Integer.toString(desVar.getMileUpgrade()));
        superSaverDates.setText(mDeparture[desVar.getStartMonth()-1] + " - " + mDeparture[desVar.getEndMonth()-1]);
    }

    //Initializes the controller right after it's root element has been processed
    public void initialize(URL location, ResourceBundle resources)
    {
        destList.setItems(c);
        monthDepart.setItems(mD);
    }
}
