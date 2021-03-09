package ams;

import javax.swing.JOptionPane;

public class AmsField {
//	"추가하기","검색하기","수정하기","삭제하기","목록보기"
//	항공사, 항공기 번호, 최대승각수,출발지,도착지
	String[][]arrPlane = new String[100][5];
	int cnt;
	int cLength = arrPlane[0].length;
	String result = "";
	int updateIndex;
	
	void insert(String []arPlane) {
		arrPlane[cnt] = arPlane;
		cnt++;
	}
	
	String search(String keyword,int index) {
		int arIndex[];
		
		String result = "";
		int searchcnt =0;
		for (int i = 0; i < cnt; i++) {
			if(keyword.equals(arrPlane[i][index])) {
				searchcnt++;
				updateIndex = i;
				result+=""+i+",";
			}
		}
		arIndex = new int[searchcnt];
		
		for (int i = 0; i < arIndex.length; i++) {			
			arIndex[i] = Integer.parseInt(result.split(",")[i]);//split은 지정한 문자를 기준으로 배열을 만들어줌.
		}
		return show(arIndex);
	}
//	수정하기
//	출발지, 목적지
//	출발지를 수정할지 목적지를 수정할지
//	JOptionPane.showOptionDialog사용
//	항공기 번호 입력받고 해당 항공기의 출발지와 목적지 수정
//	출발지와 목적지가 동일시 수정 실패
	void update(int bntIndex,String newValue) {
				arrPlane[updateIndex][bntIndex+3] = newValue;	//출발지 : 3, 목적지 : 4 bntIndex : 0,1 이기 때문에
	}
//	삭제하기
	boolean delete(String keyword) {
		boolean deleteCheck = false;
		
		for (int i = 0; i < cnt; i++) {
			if(arrPlane[i][1].equals(keyword)) {
				for(int j=i;j<cnt;j++) {
					arrPlane[j] = arrPlane[j+1];					
				}
				deleteCheck = true;
				cnt--;
				break;
			}
		}
		return deleteCheck;
	}
	
	String show() {
		String result = "항공사, 항공기 번호, 최대승객수,출발지,도착지\n";			
		
		for(int i=0;i<cnt;i++) {
			result+="♥";
			for(int j=0;j<cLength;j++) {
				result+=j==cLength-1?arrPlane[i][j]:arrPlane[i][j]+", ";//마지막 반복이니?
			}
			result+="\n";
		}
		
		if(cnt==0)result+="목록 없음\n";
		return result;
	}
	//검색 결과보기
	String show(int[] arIndex) {
		String result = "";
		for(int i=0;i<arIndex.length;i++) {
			result+="♥";
			for(int j=0;j<cLength;j++) {
				result+=arrPlane[arIndex[i]][j];
				result+=j==cLength-1?"":", ";
			}
			result+="\n";
		}
		if(arIndex.length==0)result+="검색결과 없음";
		return result;
	}
	
}
