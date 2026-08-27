class Solution {
    public int maxProfit(int[] prices) {
        int BuyPrice = Integer.MAX_VALUE;
        int MaxProfit = 0;

        for(int i=0; i<prices.length; i++){
            if(BuyPrice<prices[i]){
                int Profit = prices[i] - BuyPrice;
                MaxProfit = Math.max(MaxProfit, Profit);
            }else{
                BuyPrice = prices[i];
            }
        }
        return MaxProfit;
    }
}