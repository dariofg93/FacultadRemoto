Given(/^Un partido en (.*) el (.*) a las (.*) creado por (.*)$/) do |place, date, time, creator|
    user = User.where(:email => creator).first
    if user == nil
        user = User.create!(:email => creator, :password => "123456")
    end
    match = Match.create!(:place => place, :date => date, :time => time, :exclusive => false)
    MatchesUser.create!(:match_id => match.id, :user_id => user.id)
end

Given(/^Un partido EXCLUSIVO en (.*) el (.*) a las (.*) creado por (.*)$/) do |place, date, time, creator|
    user = User.create!(:email => creator, :password => "123456")
    match = Match.create!(:place => place, :date => date, :time => time, :exclusive => true)
    MatchesUser.create!(:match_id => match.id, :user_id => user.id)
end

When(/^Voy a listar todos los partidos$/) do
    visit "/matches"
end

Then(/^Deberia ver "([^"]*)"$/) do |text|
    expect(page).to have_content(text)
end

Given(/^No tengo partidos$/) do
    Match.delete_all
end

Given(/^No tengo suscripciones$/) do
    MatchesUser.delete_all
end


When(/^Voy a "([^"]*)"$/) do |link|
    first(:link, link).click
end

When(/^Lleno "([^"]*)" con "([^"]*)"$/) do |field, info|
    fill_in(field, :with => info)
end

When(/^Presiono "([^"]*)"$/) do |button|
    click_button button
end

Then(/^Deberia tener (\d+) partidos$/) do |num|
    expect(Match.count).to equal(Integer(num))
end

Given(/^Un usuario con mail "([^"]*)" y passwd "([^"]*)"$/) do |email, passwd|
    User.create!(:email => email, :password => passwd)
end

Given(/^No tengo usuarios$/) do
    User.delete_all
end
