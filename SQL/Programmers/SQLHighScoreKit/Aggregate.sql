-- 131115
-- 가격이 제일 비싼 식품
-- 식품 ID, 식품 이름, 식품 코드, 식품분류, 식품 가격
SELECT PRODUCT_ID, PRODUCT_NAME, PRODUCT_CD, CATEGORY, PRICE
FROM FOOD_PRODUCT
WHERE PRICE=(SELECT MAX(PRICE) FROM FOOD_PRODUCT)

-- 59038
-- 가장 먼저 들어온 동물은 언제 들어왔는지 조회
SELECT MIN(DATETIME) AS 시간
FROM ANIMAL_INS

-- 59406
-- 동물이 몇 마리 들어왔는지 조회
SELECT COUNT(*) AS count
FROM ANIMAL_INS

-- 59408
-- 동물의 이름은 몇 개
-- 이름이 NULL인 경우는 집계하지 않음
-- 중복되는 이름은 하나로
SELECT COUNT(DISTINCT NAME) AS count
FROM ANIMAL_INS

