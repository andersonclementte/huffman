library(ggplot2)

result <- read.table("//home//andersonc//Codes//GitHub//huffman//grafico//grafico_out.txt", header = T)
head(result)
plot(result$cont, 
    result$fila,
    type = "l",
    col = "green",
    lwd = 3, 
    xlab = "Elementos",
    ylab = "Interaçoes",
    main = "Fila vs heap")

lines(result$cont, result$heap, type="l", col = "red", lwd = 3)

legend("topleft", legend=c("Fila de prioridade", "Heap"),
       col=c("green", "red"),  lty = 30, cex = 0.8)