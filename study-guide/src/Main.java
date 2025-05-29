public class Main {
    public static void main(String[] args) {
        Bank SBIBank = new SBI();
        System.out.println("New SBI Bank Created");
        System.out.println("SBI interest rate (raw): " + SBIBank.getRateOfInterest(true));
        System.out.println("SBI interest rate (percentage): " + SBIBank.getRateOfInterest(false) + "%");
        System.out.println("SBI interest factor: " + SBIBank.getInterestFactor());

        Bank ICICIBank = new ICICI();
        System.out.println("New ICICI Bank Created");
        System.out.println("ICICI interest rate (raw): " + ICICIBank.getRateOfInterest(true));
        System.out.println("ICICI interest rate (percentage): " + ICICIBank.getRateOfInterest(false) + "%");
        System.out.println("ICICI interest factor: " + ICICIBank.getInterestFactor());

        Bank AXISBank = new AXIS();
        System.out.println("New AXIS Bank Created");
        System.out.println("AXIS interest rate (raw): " + AXISBank.getRateOfInterest(true));
        System.out.println("AXIS interest rate (percentage): " + AXISBank.getRateOfInterest(false) + "%");
        System.out.println("AXIS interest factor: " + AXISBank.getInterestFactor());

        System.out.println("completed");
    }
}