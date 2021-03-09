# import pickle
# cnt = 1
# while cnt<=50:
#     with open("{}주차.txt","w",encoding="utf8".format(cnt))as record_file:
#         record_file.write("""-{}주차 주간보고-
#         부서 : 
#         이름 : 
#         업무요약 : 
#         """.format(cnt))
for i in range(1,3):
    with open(str(i)+"주차.txt","w",encoding="utf8")as report_file:
        report_file.write("-{} 주차 주간보고 - ".format(i))
        report_file.write("\n부서 : ")
        report_file.write("\n이름 : ")
        report_file.write("\n업무 요약 : ")