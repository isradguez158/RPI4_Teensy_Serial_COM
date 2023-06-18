import ReadIMU as ReadIMU

ComPort='com3'

imu = ReadIMU.READIMU(ComPort)

while(True):

    imu.read()
    imu.decode()
    print("LIMU: " + str(imu.XIMUL)+"  RIMU: " + str(imu.XIMUR))
