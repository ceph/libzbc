add_custom_command(OUTPUT Lkvs.java Tester.java
		COMMAND javac -cp /usr/share/java/jna.jar:. Lkvs.java Tester.java)
