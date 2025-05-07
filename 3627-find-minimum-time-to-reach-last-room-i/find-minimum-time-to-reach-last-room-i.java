class Solution {

    public boolean isValid(int nx, int ny, int n, int m){
        return (nx<n && ny<m && nx>=0 && ny>=0);
    }

    public int minTimeToReach(int[][] moveTime) {

        int t = 0;

        long[][] dp =  new long[moveTime.length][moveTime[0].length];

        int n = moveTime.length;
        int m = moveTime[0].length;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dp[i][j] = Integer.MAX_VALUE;
            }
        }

        dp[0][0]=0;

        Queue<long[]> q = new LinkedList<>();

        q.add(new long[]{0,0,0});

        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};

        while(!q.isEmpty()){
            long[] temp = q.poll();
            int x = (int)temp[0];
            int y = (int)temp[1];
            long z = temp[2];
            for(int i=0;i<4;i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(isValid(nx,ny,n,m)){
                    if(Math.max(z,moveTime[nx][ny])+1<dp[nx][ny]){
                        dp[nx][ny] = Math.max(z,moveTime[nx][ny])+1;
                        q.add(new long[]{nx,ny,dp[nx][ny]});
                    }
                }
            }
        }

        return (int)dp[n-1][m-1];
        
    }
}