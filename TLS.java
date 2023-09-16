import gnu.io.CommPortIdentifier;
import gnu.io.SerialPort;
import java.io.OutputStream;
import java.util.Enumeration;

public class TrafficLightController {
    public static void main(String[] args) {
        try {
            Enumeration<?> portList = CommPortIdentifier.getPortIdentifiers();
            while (portList.hasMoreElements()) {
                CommPortIdentifier portId = (CommPortIdentifier) portList.nextElement();
                if (portId.getPortType() == CommPortIdentifier.PORT_SERIAL) {
                    if (portId.getName().equals("COM1")) { // Change to the correct COM port
                        SerialPort serialPort = (SerialPort) portId.open("TrafficLightController", 2000);
                        OutputStream outputStream = serialPort.getOutputStream();

                        // Send commands to the Arduino
                        String command = "G"; // For example, "G" to turn the light green
                        outputStream.write(command.getBytes());

                        serialPort.close();
                    }
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
