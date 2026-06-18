

  display.clearDisplay();

  display.fillRect(playerX, playerY, playerSize, playerSize, SSD1306_WHITE);

  display.fillRect(obstacleX, obstacleY, obstacleSize, obstacleSize, SSD1306_WHITE);

  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("Score:");
  display.print(score);

  display.display();

  delay(30);
}