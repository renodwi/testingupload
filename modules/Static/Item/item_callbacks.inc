hook OnGameModeInit()
{
    // Drinks
    CreateItem("Air Mineral", "Botol", "Dapat mengurangi tingkat dehidrasi sebesar +10", ITEM_CATEGORY_DRINK, ITEM_TYPE_WATER, 19570, 5, 10, 10.0);
    CreateItem("Alcohol", "Unit", "Memberikan efek mabuk selama 20 detik dan mengurangi jumlah dehidrasi sebesar +7", ITEM_CATEGORY_DRINK, ITEM_TYPE_ALCOHOL, 1509, 5, 7, 7.0);
    CreateItem("Jus Jeruk", "Juice", "Dapat mengurangi tingkat dehidrasi sebesar +12 dan dapat mengurangi tingkat kelaparan sebesar +3", ITEM_CATEGORY_DRINK, ITEM_TYPE_ORANGEJUICE, 19824, 5, 13, 13.0);
    CreateItem("Jus Apel", "Juice", "Dapat mengurangi tingkat dehidrasi sebesar +13 dan dapat mengurangi tingkat kelaparan sebesar +2", ITEM_CATEGORY_DRINK, ITEM_TYPE_APPLEJUICE, 19564, 5, 13, 13.0);
    CreateItem("Soda", "Unit", "Dapat mengurangi tingkat dehidrasi sebesar +11", ITEM_CATEGORY_DRINK, ITEM_TYPE_COKE, 2647, 5, 11, 11.0);

    // Foods
    CreateItem("Pizza", "Unit", "Dapat mengurangi tingkat kelaparan sebesar +20", ITEM_CATEGORY_FOOD, ITEM_TYPE_PIZZA, 2814, 2, 20, 20.0);
    CreateItem("Burger", "Unit", "Dapat mengurangi tingkat kelaparan sebesar +20", ITEM_CATEGORY_FOOD, ITEM_TYPE_BURGER, 2768, 2, 20, 20.0);
    CreateItem("Snack", "Unit", "Dapat mengurangi tingkat kelaparan sebesar +10", ITEM_CATEGORY_FOOD, ITEM_TYPE_SNACK, 19565, 5, 10, 10.0);

    // Tools
    CreateItem("Pancing", "Pemakaian", "Digunakan untuk alat seperti memancing", ITEM_CATEGORY_TOOLS, ITEM_TYPE_FISHINGPOLE, 18632, 1, 100, 100.0);
    CreateItem("Kunci Inggris", "Pemakaian", "Digunakan untuk mekanik", ITEM_CATEGORY_TOOLS, ITEM_TYPE_WRENCH, 19627, 1, 100, 100.0);
    CreateItem("Gergaji", "Pemakaian", "Digunakan untuk menebang pohon", ITEM_CATEGORY_TOOLS, ITEM_TYPE_CHAINSAW, 341, 1, 9, 100.0);
    CreateItem("Linggis", "Pemakaian", "Digunakan untuk penambangan", ITEM_CATEGORY_TOOLS, ITEM_TYPE_CROWBAR, 18634, 1, 100, 100.0);
    return 1;
}