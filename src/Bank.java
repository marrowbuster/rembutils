public class Bank {
    private float rateOfInterest;
    private float interestFactor;

    public Bank(float rateOfInterest) {
        if (rateOfInterest < 0f) {
            throw new IllegalArgumentException("negative interest rate entered");
        }
        if (rateOfInterest > 1f) {
            rateOfInterest /= 100f;
        }
        this.rateOfInterest = rateOfInterest;
        this.interestFactor = 1f + this.rateOfInterest;
    }

    public Bank() {
        this(0f);
    }

    public void setRateOfInterest(float rateOfInterest) {
        if (rateOfInterest < 0f) {
            throw new IllegalArgumentException("negative interest rate entered");
        }
        if (rateOfInterest > 1f) {
            rateOfInterest /= 100f;
        }
        this.rateOfInterest = rateOfInterest;
        this.interestFactor = 1f + this.rateOfInterest;
    }

    public float getRateOfInterest(boolean raw) {
        return raw ? this.rateOfInterest : this.rateOfInterest * 100f;
    }

    public float getInterestFactor() {
        return this.interestFactor;
    }
}
